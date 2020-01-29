//test de la classe commande
#include "produit.h"
#include <iostream>
#include "commande.h"
#include "client.h"


int main() {
	std::vector<Produit*> panier;
Client client1(1, "Nom", "prenom", panier );

Client *ref_client;
ref_client = &client1;

Produit p1("PS5", " Console de jeu de marque Sony", 249.99, 10);
Produit p2("Xbox", " Console de jeu ", 349.66, 15);


//Creation d'un pointeur
Produit *ref_pr1;
//On affecte la valeur du pointeur au contenu de p1
ref_pr1 = &p1;

Produit *ref_pr2;
ref_pr2 = &p2;
 
bool statut = false;

std::vector <Produit*> liste_produit = {ref_pr1, ref_pr2};

Commande comm(ref_client, liste_produit, statut);
comm.setStatutCommande(true);

std::cout << comm << std::endl;


return 0;
}