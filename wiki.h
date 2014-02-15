#ifndef _HAVE_WIKI_HEADER
#define _HAVE_WIKI_HEADER

typedef struct WikiPageList WikiPageList;

struct WikiPageList {
	char   *name;
	time_t  mtime;
	char  *user_name;
	char  *grp_name;
};

void wiki_handle_http_request(HttpRequest *req);

void wiki_show_header(HttpResponse *res, char *page_title, int want_edit);

void wiki_show_footer(HttpResponse *res);

int wiki_init(char *home_path, int restore_WikiHelp);

WikiPageList **wiki_get_pages(int  *n_pages, char *expr);

#endif
