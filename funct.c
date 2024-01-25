#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char lireLettre()
{
    char caractere = 0;
    caractere = getchar();
    caractere = toupper(caractere);
    while(getchar() != '\n');
    return caractere;
}

int rechercheLettre(char lettre, char motMystere[], char lettreTrouvee[])
{
    int bonneLettre = 0;
    
    for (int i = 0; i < 6; i++)
    {

        if (lettre == motMystere[i])
        {
            bonneLettre = 1;
            lettreTrouvee[i] = 1;
        }
    }
    return bonneLettre;
}
