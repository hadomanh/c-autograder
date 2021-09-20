#include <stdio.h>
#include "utils/stringutils.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stdout, "USAGE: ./main {substring|word}\n");
        exit(0);
    }

    char origin[100];
    char replace[100];
    char with[100];
    
    fscanf(stdin, "%[^\n]%*c", origin);
    fscanf(stdin, "%[^\n]%*c", replace);
    fscanf(stdin, "%[^\n]%*c", with);
    
    if (strcmp("substring", argv[1]) == 0)
    {
        fprintf(stdout, "%s\n", substringReplace(origin, replace, with));
        return 0;
    }
    
    if (strcmp("word", argv[1]) == 0)
    {
        fprintf(stdout, "%s\n", wordReplace(origin, replace, with));
        return 0;
    }
    
    
    return 0;
}

