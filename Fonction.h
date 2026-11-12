#include <conio.h>   // getch()
#include <locale.h>  // setlocal()
#include <stdbool.h> // bool,false,true
#include <stdio.h>   // printf(), scanf()
#include <stdlib.h>  // srand(), rand()
#include <time.h>    // time()
#include <ctype.h>   // tolower(), toupper()

void VerifSymbole(char *joueur, int tour);

void AffichagePlateau(char *tableau, char *joueur, int *position, int dim, int tour, int nbrJ);

char symboleJoueur(char *tableau, char *SymJoueur, int joueur);

int DeplacementPlateau(char *tableauJoueur,int tour ,char de);

int evenement(int *position, char *joueur, int tour, int lancer, char dePhysique);

void UnDe(int *position, char *joueur, int tour, int lancer, char dePhysique);