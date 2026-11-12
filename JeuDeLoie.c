#include <stdio.h>  // printf, scanf
#include <locale.h> // setlocale
#include <conio.h>  // getch

#include "Fonction.h"

void main()
{
    // Sélectionner l'environnement linguistique
    setlocale(LC_ALL, "fr_FR.UTF-8");

    // Déclaration des "int"
    int nbrJoueurs, lancer, gagnant, affichage;
    int fin = 0, tourJoueur = 0;

    // Déclaration des "char"
    char veriSymbole, de;

    // Déclaration des tableaux
    int position[4] = {0};
    char Joueur[4];
    char plateau[51];

    printf("Nombre de joueurs (de 2 à 4) ? ");
    scanf("%d", &nbrJoueurs);

    while (nbrJoueurs < 2 || nbrJoueurs > 4)
    {
        printf("\nNombre de joueurs incorrect !\n");
        printf("Nombre de joueurs (de 2 à 4) ? ");
        scanf("%d", &nbrJoueurs);
    }

    for (int i = 0; i <= nbrJoueurs - 1; i++)
    {
        Joueur[i] = symboleJoueur(plateau, Joueur, i);
    }

    printf("Avez-vous un dé physique (o/n) ? ");
    scanf(" %c", &de);

    while (tolower(de) != 'o' && tolower(de) != 'n')
    {
        printf("Craractère incorrect !\n");
        printf("Avez-vous un dé physique (o/n) ? ");
        scanf(" %c", &de);
    }

    printf("\n");
    AffichagePlateau(plateau, Joueur, position, 51, tourJoueur, nbrJoueurs);

    do
    {
        printf("\nC'est au joueur %d de jouer.\n", tourJoueur + 1);

        lancer = DeplacementPlateau(Joueur, tourJoueur, tolower(de));

        position[tourJoueur] = position[tourJoueur] + lancer;

        if (position[tourJoueur] > 50)
        {
            lancer = position[tourJoueur] - 50;
            position[tourJoueur] = 50 - lancer;
        }

        printf("\n");
        AffichagePlateau(plateau, Joueur, position, 51, tourJoueur, nbrJoueurs);

        printf("\n");
        affichage = evenement(position, Joueur, tourJoueur, lancer, tolower(de));

        if (affichage == 1)
        {
            printf("\n");
            printf("\nAprès événement\n");
            AffichagePlateau(plateau, Joueur, position, 51, tourJoueur, nbrJoueurs);
        }

        if (position[tourJoueur] == 50)
        {
            fin = 1;
            gagnant = tourJoueur + 1;
        }

        tourJoueur++;

        if (tourJoueur == nbrJoueurs)
        {
            tourJoueur = 0;
        }

    } while (fin != 1);

    printf("\nLe joueur %d a gagné !", gagnant);

    printf("\nAppuyez sur une touche pour quitter...\n");
    getch();
}