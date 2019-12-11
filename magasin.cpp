#include "magasin.h"
#include <vector>
#include <string>

Magasin::Magasin(std::vector<Produit*> liste_produit, std::vector<Client*> liste_client, std::vector<Commande*> liste_commande) {
	m_produit = liste_produit;
	m_client = liste_client;
	m_commande = liste_commande;
}

//Ajoute un nouveau produit dans le vector m_produit
void Magasin::addProduit(Produit produit){

	m_produit.push_back(produit);
}



std::vector Magasin::getProduit() const {
	return m_produit;
}

std::vector Magasin::getClient() const {
	return m_client;
}

std::vector Magasin::getCommande() const {
	return m_commande;
}


std::string Magasin::afficherListeProduit(){

int taille = m_produit.size();

for(int i;i=0;i<=taille)

std::cout<<"Nom du produit : "<<std::endl;
}
