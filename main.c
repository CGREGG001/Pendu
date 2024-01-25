#include <stdio.h>
#include <stdlib.h>
#include "funct.h"

int main(int argc, char const *argv[])
{
    int nombresEssais = 10;
    char motMystere[] = "MARRON", lettreTrouvee[6] = {0}, lettre = 0;

    printf("Bienvenue dnas le jeu du pendu\n");

    while (nombresEssais > 0)
    {
        printf("Vous avez %d essais\n", nombresEssais);
        printf("Quel est le mot mystere ? ");
        for (int i = 0; i < 6; i++)
        {
            if (lettreTrouvee[i])
            {
                printf("%c", motMystere[i]);
            }
            else
            {
                printf("*");
            }
        }
        printf("\nProposez une lettre ");
        lettre = lireLettre();
        printf("%c", lettre);

        nombresEssais --;   
    }
    
    printf("\nFin du jeu\n");
    return 0;
}
