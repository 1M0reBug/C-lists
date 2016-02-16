/*
    Auteur : Rayan ROGAI + Jordan QUAGLIATINI
    Date : 16/02/2016
    Description du programme : Fonctions utiles pour le main
*/

#include "functions.h"

//Joueur ieme(Liste l, int i){ return null;}

Bool Est_vide(Liste l) {
    return (l.nb_elements == 0);
}

Bool Est_present(Liste l, char* e) {

    Joueur courant = ieme(l, 1);
    Bool ok = true;
    while(ok) {
        if(strcmp(courant.nom, e)) {
            return true;
        } else {
            courant = suivant(l, courant);
            ok = strcmp(courant.nom, "END")?false:true;
        }
    }

    return false;
}

Joueur suivant(Liste l, Joueur j) {
    int suivant = j.suivant;
    if(suivant != -1) {
        return l.tab[suivant];
    } else {
        Joueur _j;
        _j.nom="END";
        return _j;
    }
}

Joueur precedent (Liste l, Joueur j) {
    int precedent = j.precedent;
    if(precedent != -1) {
        return l.tab[precedent];
    } else {
        Joueur _j;
        _j.nom="END";
        return _j;
    }
}
