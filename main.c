#include "defs.h"

static int debug;
int lgindex;

static int usage()
{
	printf("Usage: portablewiki [options]\n"
	       "   -d, --debug           : debug mode, listens to requests from stdin\n"
	       "   -h, --home   <path>   : specify portablewiki's home directory\n"
	       "   -l, --listen <ipaddr> : specify IP address\n"
	       "   -p, --port   <port>   : specify port number \n"
	       "   -r, --restore         : restore the default WikiHelp\n"
	       "       --help            : display this help message\n"
	       "   -i, --index <length>  : override the default index length\n"
	       "   -v, --version         : display the version\n");
	exit(1);
}

int main(int argc, char **argv)
{
	HttpRequest *req  = NULL;
	int port = 8000;
	int c;
	char *portablewiki_home = NULL;
	int restore_WikiHelp = 0;
	struct in_addr address;

	/* default values */
	debug = 0;	/* normal mode */
	lgindex = 20;	/* print 20 files before to make a new index box */

	/* by default bind server to localhost */
	address.s_addr = inet_addr("127.0.0.1");

	while (1) {
		static struct option long_options[] = {
			{"debug",  no_argument,       0, 'd'},
			{"version",  no_argument,     0, 'v'},
			{"listen", required_argument, 0, 'l'},
			{"port",   required_argument, 0, 'p'},
			{"home",   required_argument, 0, 'h'},
			{"restore",   no_argument,    0, 'r'},
			{"index",  required_argument, 0, 'i'},
			{"help",   no_argument,       0,  10 },
			{0, 0, 0, 0}
		};

		/* getopt_long stores the option index here */
		int option_index = 0;

		c = getopt_long(argc, argv, "dvrl:p:h:i:10", long_options, &option_index);

		/* detect the end of the options */
		if (c == -1)
			break;

		switch (c) {
		case 0:
			break;
		case 'i': //set index length
			lgindex = atoi(optarg);
			if (lgindex == 0) lgindex = 20;
			fprintf(stderr, "Index length = %i\n", lgindex);
			break;
		case 'd':
			debug = 1;
			break;
		case 'v':
			printf("PortableWiki - version %s\n\n", VERSION);
			return 0;
		case 'p':	/* default port is 8000 */
			port = atoi(optarg);
			break;
		case 'h':	/* default home directory is ./data */
			portablewiki_home = optarg;
			break;
		case 'l':	/* listen a inet address */
			if (inet_aton(optarg, &address) == 0) {
				fprintf(stderr, "portablewiki: invalid ip address \"%s\"\n", optarg);
				exit(1);
			} else
				address.s_addr = inet_addr(optarg);
			break;
		case 'r':	/* rewrite Wikihelp page */
			restore_WikiHelp = 1;
			break;
		case 10:
			usage();
			break;
		default:
			usage();
		}
	} //end while

	wiki_init(portablewiki_home, restore_WikiHelp);

	if (debug) {
		req = http_request_new();   /* reads request from stdin */
	} else {
		req = http_server(address, port);    /* forks here */
	}

	wiki_handle_http_request(req);

	return 0;
}
