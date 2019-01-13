#include <stdio.h>
#include <stdlib.h>

#define TAILLE 5//Taille du carr�
#define X_INITIAL 3//Postion initial de X
#define Y_INITIAL 2//Postion initial de Y

typedef struct tJeton
{
    int nX;
    int nY;

}tJeton;//Structure tJeton, composer des coordon�es en X et en Y de Jeton

typedef enum Bool {true=1, false=0}Bool;//enum qui sert de Boolean

void InitTab(int nTab[TAILLE][TAILLE]);
void Moving(int nTab[TAILLE][TAILLE], tJeton *jeton, int nCpt);
void Warp(int nTab[TAILLE][TAILLE], tJeton *jeton);
void Place(int nTab[TAILLE][TAILLE], tJeton jeton, int nCpt);
void Display(int nTab[TAILLE][TAILLE]);
Bool CaseIsVoid(int nTab[TAILLE][TAILLE], tJeton jeton);


//**********************************************************
//Description : Le main.
//
//Entr�es : Aucune.
//
//Sorties :	Chaque �tapes du car� magique.
//
//Note : L�utilisateur n�entre aucune entr�e durant tout le programme.
//
//**********************************************************
int main()

{
    int nTab[TAILLE][TAILLE];
    tJeton Jeton={X_INITIAL, Y_INITIAL};
    InitTab(nTab);

    for (int nCpt = 1; nCpt < TAILLE*TAILLE+1; nCpt++)//Boucle "principal" du programme.
    {
        Moving(nTab, &Jeton, nCpt);//D�placement du "Jeton"
    }

    Display(nTab);//Affichage

    return 0;
}


//**********************************************************
//Description : Initialisation du Tableau a 0 en X et en Y
//
//Entr�es : nTab.
//
//Sorties :	le tableau nTab initialiser a 0
//
//Note : i et j repr�sente X et Y
//
//**********************************************************
void InitTab(int nTab[TAILLE][TAILLE])
{
    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            nTab[i][j] = 0;//Initialisation a 0
        }
    }
}


//**********************************************************
//Description : "Warp" permet de faire un car� "sph�rique" quand le jeton sortira des limites il sera remit de l'autre c�t�
//
//Entr�es : le tableau nTab, et le jeton (pointeur)
//
//Sorties :	Nouvelle valeurs pour jeton->nX OU jeton->nY
//
//Note : Chaque if repr�sente un des "c�t�s" du car� magique, Droite, Gauche, Bas, Haut
//
//**********************************************************
void Warp(int nTab[TAILLE][TAILLE], tJeton *jeton)
{
    if (jeton->nX == TAILLE+1)
    {
        jeton->nX = 1;
    }
    else if (jeton->nX == 0)
    {
        jeton->nX = TAILLE;
    }

    if (jeton->nY == TAILLE+1)
    {
        jeton->nY = 1;
    }
    else if (jeton->nY == 0)
    {
        jeton->nY = TAILLE;
    }
}


//**********************************************************
//Description : V�rification de la valeur de la case, si elle vaut 0 elle est vide, sinon elle est remplie
//
//Entr�es : le tableau nTab, et le jeton
//
//Sorties :	true ou false (enum�ration Bool)
//
//Note : X
//
//**********************************************************
Bool CaseIsVoid (int nTab[TAILLE][TAILLE], tJeton jeton)
{
    if(nTab[jeton.nX-1][jeton.nY-1]==0)// Si la case est vide
    {
        return true;//Retourner true
    }
    else
    {
        return false;//Sinon retourner False
    }
}


//**********************************************************
//Description : Simple procedure qui sert a affecter une valeur a la case
//
//Entr�es : le tableau nTab, le jeton et un entier.
//
//Sorties :	Aucune
//
//Note : X
//
//**********************************************************
void Place(int nTab[TAILLE][TAILLE], tJeton jeton, int nCpt)
{
    nTab[jeton.nX-1][jeton.nY-1] = nCpt;
}


//**********************************************************
//Description :  procedure qui permet le d�placement du jeton sur le tablau.
//
//Entr�es : le tableau nTab, le jeton (pointeur) et un entier.
//
//Sorties :	Aucune
//
//Note : X
//
//**********************************************************
void Moving(int nTab[TAILLE][TAILLE], tJeton *jeton, int nCpt)
{
    if(CaseIsVoid(nTab, *jeton) == true)// Si la case est vide (utilisation de la fonction CaseIsVoid )
    {
        Place(nTab, *jeton, nCpt);
    }

    jeton->nX++;//position nX +
    jeton->nY--;//position nY -
    Warp(nTab, jeton);//Lacement de Warp (v�rification de si le jeton sort des limites de la map)
    Display(nTab);//Lancement Display de Affichage du tableau
    printf("\n");//Saut de ligne

    if(CaseIsVoid(nTab, *jeton) == false && nCpt != TAILLE*TAILLE)//Si la case n'est pas vide  (utilisation de la fonction CaseIsVoid )
    {
        jeton->nX--;
        Warp(nTab, jeton);
        jeton->nX--;
        Warp(nTab, jeton);
    }
}

//**********************************************************
//Description :  Proc�dure qui s'occupe de l'affichage du carr� magique
//
//Entr�es : le tableau nTab.
//
//Sorties :	Affichage
//
//Note : X
//
//**********************************************************
void Display(int nTab[TAILLE][TAILLE])
{
    for (int y = 0; y < TAILLE; y++)
    {
        for (int x = 0; x < TAILLE; x++)
        {
            printf("%2d ", nTab[x][y]);//Afichage du tableau en X et Y
        }
        printf("\n");//Saut de ligne
    }
}


