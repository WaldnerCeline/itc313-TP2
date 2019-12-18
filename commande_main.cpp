//test de la classe commande
#include "produit.h"
#include <iostream>
#include "commande.h"
//#include "client.h"


int main() {
//Client client1();
//Client* = new ref_client;
//*ref_client = client1;

Produit p1("PS5", " Console de jeu de marque Sony", 249.99, 10);
Produit p2("Xbox", " Console de jeu ", 349.66, 15);


Produit *ref_p1;
ref_p1 = &p1;

Produit *ref_p2;
ref_p2 = &p2;
 
bool statut = false;

std::vector <Produit*> liste_produit = {ref_p1, ref_p2};

Commande comm(/*ref_client,*/ liste_produit, statut);
comm.setStatutCommande(true);

std::cout << comm << std::endl;


return 0;
}