#include "monty.h"
int _getline(FILE* f, char* str)
{

    int c;
    int i = 0;

    while ((c = fgetc(f)) != EOF && c != '\n'){
        *(str + i++) = c;
    }
    *(str + i) = '\0';
    return i;
}
