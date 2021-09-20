#ifndef _STRING_UTILS_H_
#define _STRING_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isWord(char *toCheck, int expectedLen);

// You must free the result if result is non-NULL.
char *substringReplace(char *origin, char *replace, char *with);

char *wordReplace(char *origin, char *replace, char *with);

#endif
