/*
    Auteur : Rayan ROGAI + Jordan QUAGLIATINI
    Date : 16/02/2016
    Description du programme : Permet de jouer à la patate chaude
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

void patate_1();
void patate_2();

int main() {

    printf("Choisir la variante :\n[1] avec elimination\n[2] sans eliminination\n>");
    int read = 1;
    scanf("%i", &read);

    if(read == 1) {
        patate_1();
    } else {
        patate_2();
    }

    return 0;
}

/** Ici on joue à la version de la patate chaude avec élimination
  */
void patate_1() {
    srand(time(0));
    int nbTours = rand()%10;

    int i = 0;

    Liste liste = init();

    Joueur courant = liste.tab[0];
    Joueur tmpCourant;

    while(liste.nb_elements > 1) {
        for(i = 0; i < nbTours; i++) {
            printf("%s a la patate\n", courant.nom);
            courant = suivant(liste, courant);
        }
        tmpCourant = suivant(liste, courant);

        supprimer(&liste, courant);
        printf("** %s est éliminé **\n\n", courant.nom);


        courant = tmpCourant;
    }

    printf("-- %s Gagne !\n\n", courant.nom);
}


/** Ici on joue à la version de la patate chaude sans élimination
  */
void patate_2() {
    srand(time(0));
    //int nbIterations = rand()%15;
    int nbTours = rand()%10 + 1;

    int i = 0;
    int j = 0;

    Liste liste = init();

    Joueur courant = Tete(liste);
    Joueur tmpCourant;

    while(!eachPlayerHasLostOnce(liste)) {

        for(i = 0; i < nbTours; i++) {
            printf("%s a la patate\n", courant.nom);
            courant = suivant(liste, courant);
        }
        tmpCourant = suivant(liste, courant);

        courant.nbFroide++;
        printf("** %s perd un point **\n\n", courant.nom);


        courant = tmpCourant;
        j++;
    }

    int min = j;
    j = 1;
    while(j < liste.nb_elements) {
        courant = liste.tab[0];
        if(courant.nbFroide < min) {
            min = courant.nbFroide;
            tmpCourant = courant;
        }
        courant = suivant(liste, courant);
        j++;
    }
    printf("-- %s Gagne !\n\n", tmpCourant.nom);
}
