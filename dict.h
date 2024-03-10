#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define dictionary struct dict

struct dict {
        char key[16];
        char value[16];
};

char* dictk(int a, struct dict abc[a], char* key);

char* dictk(int a, struct dict abc[a], char* key)
{
        char *ret = NULL;
        int equ = -1;
        for (int b = 0; b < a; b++)
        {
                if (abc[b].key == "\0") {printf("null");}
                else
                {
                        if (strcmp(abc[b].key, key) == 0)
                        {
                                equ = b;
                        }
                }
        }
        if (equ != -1)
        {
                ret = malloc(strlen(abc[equ].value) + 1);
                if (ret != NULL)
                {
                        strcpy(ret, abc[equ].value);
                }
                else
                {
                        strcpy(ret, "\0");
                }
        }
        else {ret = malloc(4); strcpy(ret, "inf");}
        return ret;
}

#define setdict(d, k, v, i) strcpy(d[i].key, k); strcpy(d[i].value, v); i++;
