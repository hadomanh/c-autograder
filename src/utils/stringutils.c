#include "stringutils.h"

char *substringReplace(char *origin, char *replace, char *with)
{
    char *result;   // the return string
    char *ins;      // the next insert point
    char *tmp;      // varies
    int replaceLen; // length of replace (the string to remove)
    int withLen;    // length of with (the string to replacelace replace with)
    int frontLen;   // distance between replace and end of last replace
    int count;      // number of replacelacements

    // Sanity checks and initialization
    if (!origin || !replace)
        return NULL;
    replaceLen = strlen(replace);
    if (replaceLen == 0)
        return NULL; // Empty replace causes infinite loop during count
    if (!with)
        with = "";
    withLen = strlen(with);

    // Count the number of replacelacements needed
    ins = origin;
    for (count = 0; (tmp = strstr(ins, replace)); ++count)
    {
        ins = tmp + replaceLen;
    }

    tmp = result = (char *)malloc(strlen(origin) + (withLen - replaceLen) * count + 1);

    if (!result)
        return NULL;

    // First time through the loop, all the variable are set correctly
    // from here on,
    // tmp points to the end of the result string
    // ins points to the next occurrence of replace in origin
    // origin points to the remainder of origin after "end of replace"
    while (count--)
    {
        ins = strstr(origin, replace);
        frontLen = ins - origin;
        tmp = strncpy(tmp, origin, frontLen) + frontLen;
        tmp = strcpy(tmp, with) + withLen;
        origin += frontLen + replaceLen; // Move to next "end of replace"
    }
    strcpy(tmp, origin);
    return result;
}

int isWord(char *toCheck, int expectedLen)
{
    return (!isalnum(*(toCheck - 1))) && !isalnum(*(toCheck + expectedLen));
}

char *wordReplace(char *origin, char *replace, char *with)
{
    char *result;   // the return string
    char *ins;      // the next insert point
    char *tmp;      // varies
    int replaceLen; // length of replace (the string to remove)
    int withLen;    // length of with (the string to replacelace replace with)
    int frontLen;   // distance between replace and end of last replace
    int count;      // number of replacelacements

    // Sanity checks and initialization
    if (!origin || !replace)
        return NULL;
    replaceLen = strlen(replace);
    if (replaceLen == 0)
        return NULL; // Empty replace causes infinite loop during count
    if (!with)
        with = "";
    withLen = strlen(with);

    // Count the number of replacelacements needed
    tmp = ins = origin;
    count = 0;
    for (count = 0; (tmp = strstr(ins, replace)); ++count)
    {
        if (!isWord(tmp, replaceLen))
        {
            count--;
        }
        ins = tmp + replaceLen;
    }

    tmp = result = malloc(strlen(origin) + (withLen - replaceLen) * count + 1);

    if (!result)
        return NULL;

    // First time through the loop, all the variable are set correctly
    // from here on,
    // tmp points to the end of the result string
    // ins points to the next occurrence of replace in origin
    // origin points to the remainder of origin after "end of replace"
    while (count--)
    {
        ins = strstr(origin, replace);
        frontLen = ins - origin;
        tmp = strncpy(tmp, origin, frontLen) + frontLen;

        if (!isWord(origin + frontLen, replaceLen))
        {
            tmp = strcpy(tmp, replace) + replaceLen;
            count++;
        }
        else
        {
            tmp = strcpy(tmp, with) + withLen;
        }

        origin += frontLen + replaceLen;
    }
    strcpy(tmp, origin);
    return result;
}
