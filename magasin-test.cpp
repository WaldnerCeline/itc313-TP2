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
	std::vector<Client*> liste_client;
	std::vector<Commande*> liste_commande;
	std::vector<Commande*> commande;
	Magasin EasyStore(liste_produit, liste_client, liste_commande);
	Client c1(1,"Dupont","Pierre",panier);
	Client *ref_client;
	ref_client = &c1;
	Produit p1("Jambon","Le jambon c'est bon",8.5,10);
	Produit *ref_produit;
	ref_produit = &p1;
	EasyStore.ajouterProduit(ref_produit);
	EasyStore.afficherListeProduit();
	EasyStore.ajouterClient(ref_client);
	EasyStore.afficherListeClient();
	EasyStore.ajouterProduitClient(ref_client, ref_produit, 3);
	int id = EasyStore.validerCommande(ref_client);
	//EasyStore.changerStatutCommande(id);
return 0;
}
