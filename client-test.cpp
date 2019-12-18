#include "client.h"
#include "produit.h"
#include <iostream>
#include <vector> 

int main() {

Produit p1("Jambon","Le jambon c'est bon",8.5,2);
Produit p2("Pâtes","Les pâtes c'est bon aussi",10.5,4);


//Creation d'un pointeur
Produit *ptr1;
//On affecte la valeur du pointeur au contenu de p1
ptr1 = &p1;

Produit *ptr2;
ptr2 = &p2;

//Creation du vector panier
std::vector<Produit*> panier;




Client c1(1,"Dupont","Pierre",panier);
std::cout<<c1<<std::endl;

c1.ajouterProduit(ptr1);
c1.ajouterProduit(ptr2);

std::cout<<c1<<std::endl;

c1.changerQuantite(ptr2,1000);
std::cout<<c1<<std::endl;

c1.supprimerProduit(ptr2);
std::cout<<c1<<std::endl;


c1.viderPanier();
std::cout<<c1<<std::endl;

return 0;
}
