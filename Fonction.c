#include "Fonction.h"

void VerifSymbole(char *joueur, int tour)
{
    char symbole;

    printf("Joueur %d veuiller remettre votre symbole. ", tour + 1);
    scanf(" %c", &symbole);

    while (symbole != joueur[tour])
    {
        printf("Symbole inccorect !");
        printf("\nJoueur %d veuiller remettre votre symbole. ", tour + 1);
        scanf(" %c", &symbole);
    }
}

void AffichagePlateau(char *tableau, char *joueur, int *position, int dim, int tour, int nbrJ)
{
    for (int i = 0; i <= dim - 1; i++)
    {
        tableau[i] = ' ';
    }

    for (int j = 0; j <= dim - 1; j++)
    {

        if (position[0] == position[1] && position[0] == position[2] && position[0] == position[3] && position[1] == position[2] && position[1] == position[3] && position[2] == position[3])
        {
            tableau[position[tour]] = joueur[tour];
        }
        else
        {
            for (int k = 0; k < nbrJ; k++)
            {
                tableau[position[k]] = joueur[k];
            }
        }

        printf("|%2c", tableau[j]);
    }
    printf("|\n");

    for (int l = 0; l <= dim - 1; l++)
    {
        printf("|%2d", l);
    }
    printf("|\n");
}

char symboleJoueur(char *tableau, char *SymJoueur, int joueur)
{
    char caractere;

    printf("Quel caractère voulez vous pour te représenter joueur %d ? ", joueur + 1);
    scanf(" %c", &caractere);

    while (caractere == SymJoueur[0] || caractere == SymJoueur[1] || caractere == SymJoueur[2] || caractere == SymJoueur[3])
    {
        printf("Caractère déjà utilisé !\n");
        printf("Quel caractère voulez vous pour te représenter ? ");
        scanf(" %c", &caractere);
    }

    return caractere;
}

int DeplacementPlateau(char *tableauJoueur, int joueur, char de)
{
    int lancerDe, lancerTotal = 0;

    srand(time(NULL));

    VerifSymbole(tableauJoueur, joueur);

    if (tolower(de) == 'o')
    {
        printf("Joueur %d lancé les 2 dés et dites moi le résultat. ", joueur + 1);
        scanf("%d", &lancerTotal);

        while (lancerTotal > 12 || lancerTotal < 2)
        {
            printf("Résultat impossible ! Cheating is bad !\n");
            printf("Joueur %d relancé les 2 dés et dites moi le résultat. ", joueur + 1);
            scanf("%d", &lancerTotal);
        }
    }
    else
    {
        printf("\nVous lancez 2 dés.\n");
        for (int m = 1; m <= 2; m++)
        {
            lancerDe = (rand() % 6) + 1;

            lancerTotal = lancerTotal + lancerDe;
        }
        printf("Vous avancez de %d cases.\n", lancerTotal);
    }

    return lancerTotal;
}

int evenement(int *position, char *joueur, int tour, int lancer, char dePhysique)
{
    char rejoue;

    switch (position[tour])
    {
    case 2:
        printf("Avancez de 20 cases !\n");
        position[tour] = position[tour] + 20;
        return 1;
        break;

    case 5:
        printf("Doublez votre lancer de dé.\n");
        position[tour] = position[tour] + lancer;
        return 1;
        break;

    case 10:
        printf("Rejouez !\n");
        position[tour] = position[tour] + DeplacementPlateau(joueur, tour, dePhysique);
        return 1;
        break;

    case 12:
        printf("Avancez jusqu'à la pochaine dizaine\n");
        position[tour] = position[tour] + (10 - (position[tour] % 10));
        return 1;
        break;

    case 15:
        printf("Double ton lancer de dé.\n");
        position[tour] = position[tour] + lancer;
        return 1;
        break;

    case 17:
        UnDe(position, joueur, tour, lancer, dePhysique);
        return 1;
        break;

    case 20:
        printf("Rejouez !\n");
        position[tour] = position[tour] + DeplacementPlateau(joueur, tour, dePhysique);
        return 1;
        break;

    case 25:
        printf("Double ton lancer de dé.\n");
        position[tour] = position[tour] + lancer;
        return 1;
        break;

    case 30:
        printf("Rejouez !\n");
        position[tour] = position[tour] + DeplacementPlateau(joueur, tour, dePhysique);
        return 1;
        break;

    case 34:
        UnDe(position, joueur, tour, lancer, dePhysique);
        return 1;
        break;

    case 35:
        printf("Double ton lancer de dé.\n");
        position[tour] = position[tour] + lancer;
        return 1;
        break;

    case 40:
        printf("Vous reculez jusqu'à la case 20.\n");
        position[tour] = 20;
        return 1;
        break;

    case 48:
        printf("Reculez jusqu'à la pochaine dizaine\n");
        position[tour] = position[tour] - (position[tour] % 10);
        return 1;
        break;

    case 49:
        printf("Vous retournez à la case départ !");
        position[tour] = 0;
        return 1;
        break;

    default:
        printf("Aucun événement ne s'est produit.\n\n");
        return 0;
        break;
    }
}

void UnDe(int *position, char *joueur, int tour, int lancer, char dePhysique)
{
    char lancerDe;

    srand(time(NULL));

    VerifSymbole(joueur, tour);

    if (dePhysique == 'o')
    {
        printf("Joueur %d lancé 1 dé et dites moi le résultat. ", tour + 1);
        scanf("%d", &lancer);

        while (lancer > 6 || lancer < 1)
        {
            printf("Résultat impossible ! Cheating is bad !\n");
            printf("Joueur %d relancé 1 dé et dites moi le résultat. ", tour + 1);
            scanf("%d", &lancer);
        }
    }
    else
    {
        printf("Vous avez lancé 1 dé.\n");
        lancer = rand() % 6 + 1;
        printf("Le dé est tombré sur le %d.\n", lancer);
    }

    switch (lancer)
    {
    case 1:
        printf("Reculez jusqu'à la pochaine dizaine\n");
        position[tour] = position[tour] - (position[tour] % 10);
        break;
    case 2:
        printf("Vous reculez de 3 case.\n");
        position[tour] = position[tour] - 3;
        break;
    case 3:
        printf("Vous rejouez !\n");
        position[tour] = position[tour] + DeplacementPlateau(joueur, tour, dePhysique);
        break;
    case 4:
        printf("Il ne se passe rien\n");
        position[tour] = position[tour];
        break;
    case 5:
        printf("Vous avancez de 3 case.\n");
        position[tour] = position[tour] + 3;
        break;
    case 6:
        printf("Avancez jusqu'à la pochaine dizaine\n");
        position[tour] = position[tour] + (10 - (position[tour] % 10));
        break;
    }
}