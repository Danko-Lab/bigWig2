/* Implementation file for some portability stuff mostly aimed
 * at making the same code run under different web servers.
 *
 * This file is copyright 2002 Jim Kent, but license is hereby
 * granted for all use - public, private or commercial. */

#include "common.h"
//#include "htmshell.h"
#include "portable.h"
//#include "obscure.h"
//#include "portimpl.h"
#include <dirent.h>

void makeDirsOnPath(char *pathName)
/* Create directory specified by pathName.  If pathName contains
 * slashes, create directory at each level of path if it doesn't
 * already exist.  Abort with error message if there's a problem.
 * (It's not considered a problem for the directory to already
 * exist. ) */
{

/* shortcut for paths that already exist */
if (fileExists(pathName))
    return;

/* Make local copy of pathName. */
int len = strlen(pathName);
char pathCopy[len+1];
strcpy(pathCopy, pathName);

/* Tolerate double-slashes in path, everyone else does it. */

/* Start at root if it's an absolute path name. */
char *s = pathCopy, *e;
while (*s++ == '/')
    /* do nothing */;

/* Step through it one slash at a time
 * making directory if possible, else dying. */
for (; !isEmpty(s); s = e)
    {
    /* Find end of this section and terminate string there. */
    e = strchr(s, '/');
    if (e != NULL)
	*e = 0;
    makeDir(pathCopy);
    if (e != NULL)
	*e++ = '/';
    }
}

