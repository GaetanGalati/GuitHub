#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TAILLE 3999
void DECIvRome();
void ROMEvDeci();

int main()
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Description : Choix de l'utilisateur
//
//Entr�es : Un entier
//
//Sortie : Lancement d'une des PROCEDURE
//
//Notes : Boucle tant que le choix n'est pas �gale a 1 ou 2
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

{
    int nChoix = 0;
do{
    printf("TRADUCTEUR DE CHIFFRE ROMAIN\n");
    printf("\n");
    printf("1 : Decimal Vers Romain \n");
    printf("2 : Romain Vers Decimal\n");
    scanf("%d",&nChoix);

    switch (nChoix){

            case 1: DECIvRome();break;
            case 2: ROMEvDeci();break;
            default:;break;
    }
}
while (nChoix <=0 || nChoix >=3);

return 0;
}
void DECIvRome(){
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Description : Proc�dure qui va convertir un nombre d�cimal en un nombre romain via une boucle wihle, qui va boucler jussqu'a ce que nombre soit �gale � 0, � chaque it�ration la boucle va v�rifier la valeur du nombre et �crire un chiffre romain, elle enl�vera ensuite au nombre l'�quivalent d�cimal de ce que vaut le chiffre romain
//
//Entr�es : Un Entier
//
//Sortie : "Un chiffre romain" qui est en r�alit� une suite de character (X,V,C,M...)
//
//Notes : � la base, je voulais le faire via un syst�me de "case of", cependant le switch Case fonctionne uniquement via des constantes (Case >= 1000 est impossible) Je n'ai pas trouver comment palier a cela et donc j'ai fais le m�me programme avec un syst�me "If else"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    int nNombre=0;

    printf("Entrez le nombre que vous voullez traduire, Cesar ! \n");
    scanf("%d",&nNombre);//Lecture du nombre : Exemple 1550
    printf("Votre nombre Decimal : %d\n",nNombre);//Votre nombre Decimal = 1550

    if (nNombre <=0 || nNombre >TAILLE){
                //Si le nombre est trop grand, ou trop petit : Erreur !
                printf("Erreur, C'est un village peuple d'irreductibles Gaulois ! Entrez un nombre entre 1 et 3999 ! ");//Cas o� l'utilisateur rentrerais un NB plus grand que 3999 ou plus petit que 0
            }

    printf("Votre nombre Romain :");
    while (nNombre != 0){//Tant que le nombre n'est pas 0


                if(nNombre >= 1000){//Notre nombre �tant 1550...

                    printf("M");//...Le programme �crit "M"
                    nNombre -=1000;//Il enl�ve 1000, notre nombre et 550, et le programme reboucle

                }else
                if(nNombre >= 900){

                    printf("CM");
                    nNombre -=900;

                }else
                if(nNombre >= 500){//Notre nombre �tant 550...

                    printf("D");//...Le programme �crit D, Donc MD
                    nNombre -=500;//Et il enl�ve 500, notre nombre est donc 50, le programme reboucle

                }else
                if(nNombre >= 400){

                    printf("CD");
                    nNombre -=400;

                }else
                if(nNombre >= 100){

                    printf("C");
                    nNombre -=100;

                }else
                if(nNombre >= 90){

                    printf("XC");
                    nNombre -=90;

                }else
                if(nNombre >= 50){//Notre nombre �tant 50...

                    printf("L");//Le programme �crit L a cote de MD, se qui fait MDL, 1550 en chiffre romain
                    nNombre -=50;//50-50 = 0, Donc fin de la boucle tant que nombtre != de 0 !

                }else
                if(nNombre >= 40){

                    printf("XL");
                    nNombre -=40;

                }else
                if(nNombre >= 10){

                    printf("X");
                    nNombre -=10;

                }else
                if(nNombre >= 9){

                    printf("IX");
                    nNombre -=9;

                }else
                if(nNombre >= 5){

                    printf("V");
                    nNombre -=5;

                }else
                if(nNombre >= 4){

                    printf("IV");
                    nNombre -=4;

                }else
                if(nNombre >= 1){

                    printf("I");
                    nNombre -=1;

                }


}
}

void ROMEvDeci(){
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Description : Proc�dure qui va convertir un nombre Romain (Cha�ne de caract�res) en un nombre d�cimal via un switch case et une boucle pour, la boucle va incr�menter une variable "I", qui, si le caract�re correspond � un chiffre roain, va l'affecter au tableau en position I
//
//Entr�es : Une chaine de caracter (X,V,C,M...)
//
//Sortie : "Un chiffre romain" qui est en r�alit� une suite de caracter (X,V,C,M...)
//
//Notes : X
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    int nVerif[100];
    int nRoman;
    int nLongRome;
    int i;
    char cRoman[100];
    printf("Entez le nombre Romainque vous voullez traduire, Cesar !\n");
    scanf("%s",cRoman);//Exemple : MDL
    nLongRome=strlen(cRoman)-1;//nLongRome prend la valeur de la longeur de la chaine (-1 pour le caract de fin de chaine), il prend donc 3
    for(i=0; i<nLongRome; i++)//Pour i=0 jussqu'a 3...
        {

            switch(cRoman[0]) {
                case 'I': nVerif[i] = 1;break;
                case 'V': nVerif[i] = 5; break;
                case 'X': nVerif[i] = 10;break;
                case 'L': nVerif[i] = 50;break;//iter 3: Notre 3emm lettre est L donc 50, 1000 + 500 + 50 = 1550, MDL
                case 'C': nVerif[i] = 100;break;
                case 'D': nVerif[i] = 500;break;//Iter 2: Notre 2emm lettre est D, donc 500, 1000+500 = 1500
                case 'M': nVerif[i] = 1000;break;//Iter 1: Notre 1er lettre est 'M", donc 1000
            default : printf("\nNombre invalide ! ");break; }

    }
     nRoman=nVerif[nLongRome-1];//-1 pour le caract de fin de chaine

     printf("Votre nombre Romain :%s\n",cRoman );
     printf("Votre nombre Entier : ");
     printf("%d\n",nRoman);//Ecrire 1550.

}


