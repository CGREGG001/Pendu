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

        for (int i = 0; i < 6; i++)             //boucle pour lire le motMystere
        {
            if (lettreTrouvee[i])               //si une lettre correcte
            {
                printf("%c", motMystere[i]);    //on affiche celle-ci
            }
            else
            {
                printf("*");                    //sinon on affiche une *
            }
        }

        printf("\nProposez une lettre ");       
        lettre = lireLettre();                  //appel de la fonction = saisie par le joueur d'une lettre
        
        if (!rechercheLettre(lettre, motMystere, lettreTrouvee))    //si lettre PAS correcte alors
        {
            nombresEssais--;                                        //-1 coup
        }
    }

    printf("\nFin du jeu\n");
    return 0;
}
