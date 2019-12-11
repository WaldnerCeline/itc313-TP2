#include "produit.h"
#include <iostream>


int main() {

Produit objet("PS5", " Console de jeu de marque Sony", 249.99, 10);
std::cout << objet<<std::endl;
double prix = objet.getPrix();
std::cout << "prix :"<< prix<< std::endl;

return 0;
}