#include "produit.h"
#include <iostream>


int main() {

Produit objet("PS5", " Console de jeu de marque Sony", 249.99, 10);
std::cout << objet<<std::endl;
double prix = objet.getPrix();
double quantite = 6;
double retour;
objet.setQuantiteCommande(quantite);
retour = objet.getQuantiteCommande();
std::cout<< " quantite "<< retour<<std::endl;
std::cout << "prix :"<< prix<< std::endl;

return 0;
}