#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "types.h"
#include <stdio.h>
#include <string.h>

Joueur ieme(Liste l, int i);
Liste init();
Bool Est_vide(Liste l);
Bool Est_present(Liste l, char* e);
Joueur suivant(Liste l, Joueur j);
Joueur precedent (Liste l, Joueur j);
void supprimer(Liste* l, Joueur j);
void ajouter(Liste l, Joueur j);
Bool isDeleted(Joueur j);
Bool isHead(Liste l, Joueur j);
Bool eachPlayerHasLostOnce(Liste l);
Joueur Tete(Liste l);


#endif //FUNCTIONS_H
