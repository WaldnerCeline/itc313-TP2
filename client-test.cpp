#include "client.h"
#include "produit.h"
#include <iostream>
#include <vector> 

int main() {

Produit p1("titre1","desc1",8.5,2);
Produit p2("titre2","desc2",10.5,4);


//Creation d'un pointeur
Produit *ptr1;
//On affecte la valeur du pointeur au contenu de p1
ptr1 = &p1;

Produit *ptr2;
ptr2 = &p2;

//Creation du vector panier
std::vector<Produit*> panier;




Client c1(1,"NOM","PRENOM",panier);

c1.getPanier();
c1.ajouterProduit(ptr1);
c1.ajouterProduit(ptr2);

std::cout<<c1<<std::endl;

c1.getPanier();
//c1.supprimerProduit(ptr2);
//c1.getPanier();

c1.viderPanier();
c1.getPanier();

std::cout<<"OK"<<std::endl;

return 0;
}
