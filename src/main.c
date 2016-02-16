/*
    Auteur : Rayan ROGAI + Jordan QUAGLIATINI
    Date : 16/02/2016
    Description du programme : Vérifie si la syntaxe d'une phrase est correcte
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"


int main() {

    srand(time(0));
    int nbTours = rand()%10;
    int i = 0;

    Liste liste = init();

    Joueur courant = liste.tab[0];
    Joueur tmpCourant;

    while(liste.nb_elements != 1) {
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

    return 0;
}
