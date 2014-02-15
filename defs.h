#ifndef _HAVE_DIDIWIKI_HEADER
#define _HAVE_DIDIWIKI_HEADER

#define _GNU_SOURCE

#include "config.h"

#if defined(__MINGW32__)

/* This is broken */

#undef DATADIR

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <sys/stat.h>
#include <sys/timeb.h>
#include <sys/types.h>
#include <dirent.h>

#ifndef WNOHANG
#define WNOHANG 1
#endif

#ifndef F_OK
#    define F_OK 00
#endif
#ifndef X_OK
#    define X_OK 01
#endif
#ifndef W_OK
#    define W_OK 02
#endif
#ifndef R_OK
#    define R_OK 04
#endif

#else

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <sys/times.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <getopt.h>
#include <syslog.h>

#endif

#define TRUE  1
#define FALSE 0
//min. change disconnect ip below
#define DISCONNECT 30

#define PICSFOLDER "images"
#define FILESFOLDER "files"
#define ACCESSFOLDER "permission"

#include "util.h"
#include "http.h"
#include "wiki.h"

#endif
