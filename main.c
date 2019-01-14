#include <stdio.h>
#include <stdlib.h>
//CONSTANTES
#define TAILLE 5
#define MIN 0
#define CORREC 4
#define MAXVALEUR 25


//TYPE STRUCTURE
    typedef struct tPion{
        int nLigPion;
        int nColPion;
    }tPion;

//PROTOTYPES
void iniTab (int tGrille[TAILLE][TAILLE]);
void avanceNordEst(tPion *tRemplisseur);
void avanceNordOuest(tPion *tRemplisseur);
void corriger(tPion *tRemplisseur);
int rechercheVide (int tGrille[TAILLE][TAILLE], const tPion *tRemplisseur);
void avancer (int tGrille[TAILLE][TAILLE], tPion *tRemplisseur);
void placer (int tGrille[TAILLE][TAILLE],const tPion tRemplisseur,const int nCpt);
void afficheTab(const int tGrille[TAILLE][TAILLE]);

int main()
{
    int tGrille[TAILLE][TAILLE];
    int nCpt = 1;
    tPion tRemplisseur = {2,1};//La première valeur est placée en case 3,2, et on se déplace avant de placer la valeur d'ou 2,1

    printf("Hello world!\n");
    iniTab(tGrille);

    for(nCpt=1;nCpt<=MAXVALEUR;nCpt++){
        avancer(tGrille, &tRemplisseur);
        placer(tGrille, tRemplisseur, nCpt);
    }


    afficheTab(tGrille);

    return 0;
}



 //////PROCEDURE iniTab//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description : Initialise toutes les cellules de la grille à 0.
 //
 // Entrée : La grille, un tableau d'entiers à 2 dimensions.
 //
 // Sortie :La grille initialisée
 //
 // Note : aucune
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void iniTab(int tGrille[TAILLE][TAILLE]){
//var
    int nLig=0;
    int nCol=0;

    printf("Initialisation du carre.\n");

    for(nLig=0;nLig<TAILLE;nLig++){
        for(nCol=0;nCol<TAILLE;nCol++){
            tGrille[nCol][nLig]=MIN;
        }
    }
}



 //////PROCEDURE avanceNordEst//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description : Déplace le piont vers la casse situé en haut à droite de la case actuelle.
 //
 // Entrée : Une structure composé de coordonnées, un pion.
 //
 // Sortie :De nouvelles coordonnées.
 //
 // Note : aucune
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void avanceNordEst(tPion *tRemplisseur){

    tRemplisseur->nLigPion = tRemplisseur->nLigPion-1;
    tRemplisseur->nColPion = tRemplisseur->nColPion+1;
}


 //////PROCEDURE avanceNordOuest//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description : Déplace le piont vers la casse situé en haut à gauche de la case actuelle.
 //
 // Entrée : Une structure composé de coordonnées, un pion.
 //
 // Sortie :De nouvelles coordonnées.
 //
 // Note : aucune
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void avanceNordOuest(tPion *tRemplisseur){

    tRemplisseur->nLigPion = tRemplisseur->nLigPion-1;
    tRemplisseur->nColPion = tRemplisseur->nColPion-1;
}


 //////PROCEDURE corriger//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description : Déplace le piont vers la casse situé en haut à droite de la case actuelle.
 //
 // Entrée : Une structure composé de coordonnées, un pion.
 //
 // Sortie :De nouvelles coordonnées.
 //
 // Note : aucune
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void corriger(tPion *tRemplisseur){

    if (tRemplisseur->nColPion == TAILLE){
        tRemplisseur->nColPion = MIN;
    }else if (tRemplisseur->nColPion < MIN){
            tRemplisseur->nColPion = CORREC;
        }

    if (tRemplisseur->nLigPion == TAILLE){
        tRemplisseur->nLigPion = MIN;
    }else if (tRemplisseur->nLigPion < MIN){
            tRemplisseur->nLigPion = CORREC;
        }
}



 //////FONCTION recherche vide//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description : Teste une cellule pour en vérifier la valeur.
 //
 // Entrée : Une cellule de la grille.
 //
 // Sortie : La fonction retourne 1 si la cellule est vide et 0 si la cellule a déjà été initialisé.
 //
 // Note : aucune
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int rechercheVide (int tGrille[TAILLE][TAILLE], const tPion *tRemplisseur){

    if (tGrille[tRemplisseur->nColPion][tRemplisseur->nLigPion] == MIN){
        return 1;//VRAI DONC VIDE
    }else {
        return 0;//FAUX DONC DEJA INITIALISE
        }
}


 //////PROCEDURE avancer//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description : Gère le déplacement de notre pion remplisseur.
 //
 // Entrées :La grille et le pion.
 //
 // Sortie :De nouvelles coordonnées pour le pion.
 //
 // Note : aucune
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void avancer (int tGrille[TAILLE][TAILLE], tPion *tRemplisseur){

    avanceNordEst(tRemplisseur);
    corriger(tRemplisseur);

    if (rechercheVide(tGrille, tRemplisseur) == MIN){
        avanceNordOuest(tRemplisseur);
    }
    corriger(tRemplisseur);
}



 //////PROCEDURE placer//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description : Remplit le carré magique.
 //
 // Entrées : La grille, le pion, et le nombre à place dans la cellule.
 //
 // Sortie : Une cellule remplit.
 //
 // Note : aucune
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void placer (int tGrille[TAILLE][TAILLE], const tPion tRemplisseur, const int nCpt){

    tGrille[tRemplisseur.nColPion][tRemplisseur.nLigPion] = nCpt;
}




 //////PROCEDURE afficheTab/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Description : Affiche le carre magique.
 //
 // Entrées : La grille.
 //
 // Sortie : L'affichage de la grille.
 //
 // Note : aucune
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void afficheTab(const int tGrille[TAILLE][TAILLE]){

    int nLig=0;
    int nCol=0;

    for(nLig=0;nLig<TAILLE;nLig++){
        printf("\n");
        for(nCol=0;nCol<TAILLE;nCol++){
            printf(" %d  ",tGrille[nCol][nLig]);
        }
    }
}
