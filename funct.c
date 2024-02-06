/*
    nom du programme : funct.c
    description : fonction permettant de lirre le caractere du joueur et 
                  de le comparer avec le mot mystere
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "funct.h"

char lireCaractere()
{
    char caractere = 0;
    caractere = getchar();
    caractere = toupper(caractere);
    while (getchar() != '\n');
    return caractere;
}

char rechercherLettre(char lettre, char motMystere[], char lettreTrouvee[], int taille)
{
    char bonneLettre = 0;
    for (int i = 0; i < taille; i++)
    {
        if (lettre == motMystere[i])
        {
            bonneLettre = 1;
            lettreTrouvee[i] = 1;
        }
    }
    return bonneLettre;
}

int motTrouve(char lettreTrouvee[], int taille)
{
    int gagne = 1;

    for (int i = 0; i < taille; i++)
    {
        if (lettreTrouvee[i] == 0)
        {
            gagne = 0;
        }
    }
    return gagne;
}