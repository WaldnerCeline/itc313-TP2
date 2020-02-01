#include "magasin.h"
#include "client.h"
#include "produit.h"
#include "commande.h"

#include <vector>
#include <iostream>
#include <string>

int main(){
	std::vector<Produit*> liste_produit;
	std::vector<Produit*> panier;
	std::vector<Produit*> panier2;
	std::vector<Client*> liste_client;
	std::vector<Commande*> liste_commande;
	std::vector<Commande*> commande;
	int id = 1;
	Magasin EasyStore(liste_produit, liste_client, liste_commande);
	Client c1(1,"Dupont","Pierre",panier);
	Client *ref_client;
	ref_client = &c1;

	Client c2(2,"Potter","Harry",panier2);
	Client *ref_client2;
	ref_client2 = &c2;

	

	

	Produit p1("Jambon","Le jambon c'est bon",8.5,10);
	Produit *ref_produit;
	ref_produit = &p1;

	std::vector<Produit*> panier3 = {ref_produit};

	Client c3(3,"Holmes","Sherlock",panier3);
	Client *ref_client3;
	ref_client3 = &c3;

	EasyStore.ajouterProduit(ref_produit);
	//EasyStore.afficherListeProduit();
	EasyStore.ajouterClient(ref_client);
	EasyStore.ajouterClient(ref_client2);


	
	EasyStore.ajouterProduitClient(ref_client, ref_produit, 3);
	;
	EasyStore.validerCommande(ref_client3);
	EasyStore.afficherListeClient();
	EasyStore.changerStatutCommande(id);
	EasyStore.afficherListeCommande();
	//EasyStore.afficherListeCommandeClient(ref_client);
	EasyStore.afficherListeCommandeClient(ref_client2);

	EasyStore.changerStatutCommande(id);

return 0;
}
