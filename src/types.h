/*
    Auteur : Rayan ROGAI + Jordan QUAGLIATINI
    Date : 16/02/2016
    Description du programme : Déclaration des types
*/

typedef struct joueur{
    char* nom;
    Joueur *suivant;
    Joueur *precedent;
}Joueur;

typedef struct liste{
    Joueur tab[10];
    int nb_elements;
}
