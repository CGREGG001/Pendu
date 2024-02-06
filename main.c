/*
    nom programme : Jeu du Pendu
    auteur : Gregory Colard
    date : 06/02/2024
    licence : libre
    compilation : gcc -Wall *.c -o jeu
    pour executer tapez ./jeu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "funct.h"
#include "dico.h"

#define TAILLETABLEAU 20

int main(int argc, char const *argv[])
{
    int nombreCoups = 10, tailleMotMystere = 0;
    char motMystere[TAILLETABLEAU] = {0}, lettreTrouvee[TAILLETABLEAU] = {0}, lettre = 0;

    printf("\nBienvenue dans le jeu du pendu\n");

    piocherMot(motMystere);                 //utilisation de la fonction pour trouver un mot au hazard
    tailleMotMystere = strlen(motMystere);  //fonction strlen pour obtenir le nbre de caractere à afficher

    while (nombreCoups > 0 && !motTrouve(lettreTrouvee, tailleMotMystere))
    {
        printf("\nVous avez %d coups\n", nombreCoups);
        printf("Quel est le mot mystere ? ");
        for (int i = 0; i < tailleMotMystere; i++)
        {
            if (lettreTrouvee[i])               //si lettre trouvee on l'affiche
            {
                printf("%c", motMystere[i]);
            }
            else
            {
                printf("*");                    //si lettre incorrecte on affiche '*'
            }
        }
        printf("\nProposez une lettre : ");
        lettre = lireCaractere();

        if (!rechercherLettre(lettre, motMystere, lettreTrouvee, tailleMotMystere))
        {
            nombreCoups--;
        }
    }

    if (motTrouve(lettreTrouvee, tailleMotMystere) == 1)
        printf("\nBravo ! Vous avez trouve le mot mystere : %s.\n", motMystere);
    else
        printf("\nDommage, vous avez perdu ! Le mot mystere etait %s.\n", motMystere);

    printf("\nFIN\n");
    return 0;
}
