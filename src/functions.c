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

    Joueur courant = l.tab[l.tete];
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
        strcpy(_j.nom, "END");
        return _j;
    }
}

Joueur precedent (Liste l, Joueur j) {
    int precedent = j.precedent;
    if(precedent != -1) {
        return l.tab[precedent];
    } else {
        Joueur _j;
        strcpy(_j.nom, "END");
        return _j;
    }
}

void ajouter(Liste l, Joueur j) {
    int idx = 0;
    if(Est_vide(l)) {
        l.tete = 0;
    } else {
        for(idx = 0; idx<10; idx++) {
            if(l.tab[idx].precedent == -1 && l.tab[idx].suivant == -1) {
                break;
            }
        }
    }
    l.tab[idx] = j;
    l.nb_elements++;
}

void supprimer(Liste* l, Joueur j) {
    l->tab[j.precedent].suivant = j.suivant;
    l->tab[j.suivant].precedent = j.precedent;
    j.suivant = -1;
    j.precedent = -1;

    l->nb_elements--;
}


Liste init(){
  Liste liste;
  strcpy(liste.tab[0].nom, "Alain");
  liste.tab[0].suivant = 1 ;
  liste.tab[0].precedent = 9;
  liste.tab[0].nbFroide = 0;

  strcpy(liste.tab[1].nom,"Benoit");
  liste.tab[1].suivant = 2 ;
  liste.tab[1].precedent = 0;
  liste.tab[1].nbFroide = 0;

  strcpy(liste.tab[2].nom, "Christian");
  liste.tab[2].suivant = 3 ;
  liste.tab[2].precedent = 1;
  liste.tab[2].nbFroide = 0;

  strcpy(liste.tab[3].nom, "David");
  liste.tab[3].suivant = 4 ;
  liste.tab[3].precedent = 2;
  liste.tab[3].nbFroide = 0;

  strcpy(liste.tab[4].nom, "Emily");
  liste.tab[4].suivant = 5 ;
  liste.tab[4].precedent = 3;
  liste.tab[4].nbFroide = 0;

  strcpy(liste.tab[5].nom, "Francois");
  liste.tab[5].suivant = 6 ;
  liste.tab[5].precedent = 4;
  liste.tab[5].nbFroide = 0;

  strcpy(liste.tab[6].nom, "Guy");
  liste.tab[6].suivant = 7 ;
  liste.tab[6].precedent = 5;
  liste.tab[6].nbFroide = 0;

  strcpy(liste.tab[7].nom, "Henri");
  liste.tab[7].suivant = 8 ;
  liste.tab[7].precedent = 6;
  liste.tab[7].nbFroide = 0;

  strcpy(liste.tab[8].nom, "Ivan");
  liste.tab[8].suivant = 9 ;
  liste.tab[8].precedent = 7;
  liste.tab[8].nbFroide = 0;

  strcpy(liste.tab[9].nom, "Jean");
  liste.tab[9].suivant = 0 ;
  liste.tab[9].precedent = 8;
  liste.tab[9].nbFroide = 0;

  liste.tete = 0;
  liste.nb_elements = 10;

  return liste;
}
