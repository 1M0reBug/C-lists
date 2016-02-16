#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "types.h"
#include <stdio.h>
#include <string.h>

Joueur ieme(Liste l, int i);
Bool Est_vide(Liste l);
Bool Est_present(Liste l, char* e);
Joueur suivant(Liste l, Joueur j);
Joueur precedent (Liste l, Joueur j);


#endif //FUNCTIONS_H
