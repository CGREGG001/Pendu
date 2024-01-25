#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char lireLettre()
{
    char caractere;
    caractere = getchar();
    caractere = toupper(caractere);
    while(getchar() != '\n');
    return caractere;
}
