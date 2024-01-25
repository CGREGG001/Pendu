#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  //bibliothèque ctype pour la fonction toupper() mise en majuscule du caractere

//fonction de saisie de la lettre par le joueur
char lireLettre()   
{
    char caractere = 0;
    caractere = getchar();          //getchar() équivaut à scanf("%c", caractere)
    caractere = toupper(caractere); //toupper pour mettre les caracteres en MAJ
    while(getchar() != '\n');       //boucle pour vider le buffer et éliminer le \n
    return caractere;
}

//fonction pour rechercher si la lettre fait partie du motMystere, si oui ont le met en 1
int rechercheLettre(char lettre, char motMystere[], char lettreTrouvee[])
{   
    int bonneLettre = 0;
    
    for (int i = 0; i < 6; i++)
    {

        if (lettre == motMystere[i])
        {
            bonneLettre = 1;        //la lettre vaut 1, vrai se trouve dans le motMystere
            lettreTrouvee[i] = 1;   //pour placer le 1 au bon endroit de la chaine lettreTrouvee
        }
    }
    return bonneLettre;
}
