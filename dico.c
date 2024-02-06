/*
    nom programme : dico.c
    description : gestion des fonctions liees au dictionnaire
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "dico.h"

int piocherMot(char *motPioche)
{
    int caractereLu = 0, nombreMotMax = 0, numMotChoisi = 0; 

    FILE *dico = NULL;
    dico = fopen("dico.txt", "r");      //fopen pour avoir acces au fichier dictionnaire
    if (dico == NULL)                   //test réussite ouverture du fichier, sinon renvoi erreur
    {
        printf("Le fichier dico.txt est introuvable !\n");
        return 0;
    }

    do                                  //boucle pour lire l'ensemble du fichier dico et compter le nombre de '\n'
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMotMax++;
    } while (caractereLu != EOF);

    numMotChoisi = nombreAleatoire(nombreMotMax);  //sélection du numéro de mot aléatoirement

    rewind(dico);                       //relecture du fichier depuis le début
    while (numMotChoisi > 0)            //refait boucle pour lire les \n  mais décrémente numMotChoisi
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }

    fgets(motPioche, 50, dico);         //on lit le mot choisi
    motPioche[strlen(motPioche) - 1] = '\0';        //on vire le return à la fin en le remplacant par '\0'

    fclose(dico);                       //ferme le fichier dico
    return 1;                           //return 1 "tout c'est bien déroulé"
}

int nombreAleatoire(int nombreMotMax)      //fonction pour obtenir un nombre aléatoire entre 1 et le max de mot du dico
{
    srand(time(NULL));
    return (rand() % nombreMotMax);
}
