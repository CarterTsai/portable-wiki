#include "defs.h"
#include "wiki.h"

void wiki_show_changes_page(HttpResponse *res)
{
	WikiPageList **pages = NULL;
	int n_pages, i, j, m, lg;
	char spacing[24];
	char *difflink;
	int *table, *done; //alloc mem with n_pages
	char *str_ptr;

//	wiki_show_header(res, "Changes", FALSE);

	pages = wiki_get_pages(&n_pages, NULL);

	table = malloc((1 + n_pages) * sizeof(int));
	done = malloc((1 + n_pages) * sizeof(int));
    
    http_response_set_content_type(res, "text/html");
	/* regroup file and previous file */
	for (i = 0; i < n_pages + 1; i++) {
		done[i] = 0;
		table[i] = 0;
	}
	m = 0;
	for (i = 0; i < n_pages; i++)
		if (!done[i] && !strstr(pages[i]->name, ".prev.1")) {
			for (j = 0; j < n_pages; j++)
				if (!done[j]
				    && (str_ptr = strstr(pages[j]->name, pages[i]->name))
				    &&  !strcmp(str_ptr + strlen(pages[i]->name), ".prev.1")) {
					table[m++] = i;
					table[m++] = j;
					done[i] = 1;
					done[j] = 1;
					break;
				}
		}
	/* complete with new files */
	for (i = 0; i < n_pages; i++)
		if (!done[i]) table[m++] = i;

	for (j = 0; j < m; j++) {
		struct tm   *pTm;
		char   datebuf[64];
		i = table[j];
		if (strstr(pages[i]->name, ".prev.1")) {
			strcpy(spacing, "&nbsp;&nbsp;");
			lg = asprintf(&difflink,
			              "<a href='/#/Diff/%s'>diff</a>\n"
			              "<a href='/#/Comp/%s'>comp</a>\n",
			              pages[i]->name, pages[i]->name);
		} else {
			*spacing = '\0';
			difflink = strdup("\0");
		}
		pTm = localtime(&pages[i]->mtime);
		strftime(datebuf, sizeof(datebuf), "%Y-%m-%d %H:%M", pTm);
		http_response_printf(res, "%s<a href=/#/View/%s>%s</a> %s %s<br />\n",
		                     spacing,
		                     pages[i]->name,
		                     pages[i]->name,
		                     datebuf,
		                     difflink);
	}

	http_response_printf(res, "<p>Wiki changes are also available as a "
	                     "<a href='/rss'>RSS</a> feed.\n");

//	wiki_show_footer(res);
	http_response_send(res);
	free(table);
	free(done);
	exit(0);
}

/* Use cmd "diff" */
void wiki_show_diff_between_pages(HttpResponse *res, char *page, int mode)
{
	FILE *fp;
	char line[128];
	char *str_ptr;
	char *cmd;
	int val1, val2, nbln = 1, lg;
	char buffer[128];
	char action;

	if (!page) exit(0);

	char *current = strdup(page);
	*strstr(current, ".prev") = '\0';
	fp = fopen(page, "r");
	lg = asprintf(&cmd, "diff -abB %s %s", page, current);

//	wiki_show_header(res, "Changes", FALSE);

	FILE *pipe = popen(cmd, "r");
	if (!pipe)
		exit(0);

	http_response_printf(res, "<p>Current page: %s</p>\n", current);
	while (!feof(pipe)) {
		if (fgets(buffer, 128, pipe) != NULL) {
			/* Analyze results returned by diff */
			if (strchr("<>=", buffer[0]))
				http_response_printf(res, "<B>%s%s</B><br>\n",
				                     buffer[0] == '>' ? "New:" : "", &buffer[1]);
			else if ((str_ptr = strpbrk(buffer, "acd"))) {
				action = *str_ptr;
				*str_ptr = '\0';
				val1 = atoi(buffer);
				if ((str_ptr = strchr(buffer, ',')))
					val2 = atoi(str_ptr + 1);
				else
					val2 = val1;

				if (mode == 2) {
					/* Show previous page markup */
					while (nbln < val2) {
						if (!fgets(line, 128, fp))
							exit(0);
						http_response_printf(res, "%i:%s<br>\n", nbln, line);
						nbln++;
					}
				}

				/* Explain change */
				switch (action) {
				case 'd':
					http_response_printf(res, "<B>Deleted line %i-%i:<br></B>\n", val1, val2);
					break;
				case 'a':
					http_response_printf(res, "<B>Added line %i-%i:<br></B>\n", val1, val2);
					break;
				case 'c':
					http_response_printf(res, "<B>Changed line %i-%i:<br></B>\n", val1, val2);
					break;
				}
			}
		}
	}
	if (mode == 2) {
		while (fgets(line, 128, fp)) {
			http_response_printf(res, "%i:%s<br>\n", nbln, line);
			nbln++;
		}
	}

	pclose(pipe);
	fclose(fp);

//	wiki_show_footer(res);
	http_response_send(res);
	exit(0);
}

void wiki_show_changes_page_rss(HttpResponse *res)
{
	WikiPageList **pages = NULL;
	int            n_pages, i;

	pages = wiki_get_pages(&n_pages, NULL);

	http_response_set_content_type(res, "application/xhtml+xml");

	http_response_printf(res, "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n"
	                     "<rss version=\"2.0\">\n"
	                     "<channel><title>DidiWiki Changes feed</title>\n");

	for (i = 0; i < n_pages; i++) {
		struct tm   *pTm;
		char         datebuf[64];

		pTm = localtime(&pages[i]->mtime);
		strftime(datebuf, sizeof(datebuf), "%Y-%m-%d %H:%M", pTm);

		http_response_printf(res,
		                     "<item><title>%s</title>"
		                     "<link>%s%s</link><description>"
		                     "Modified %s\n",
		                     pages[i]->name,
		                     getenv("PORTABLEWIKI_URL_PREFIX") ? getenv("PORTABLEWIKI_URL_PREFIX") : "",
		                     pages[i]->name,
		                     datebuf);

		http_response_printf(res, "</description></item>\n");
	}

	http_response_printf(res, "</channel>\n</rss>");

	http_response_send(res);
	exit(0);
}
