#include "magasin.h"
#include "client.h"
#include "commande.h"
#include "produit.h"

#include <vector>
#include <string>


Magasin::Magasin(std::vector<Produit*> liste_produit, std::vector<Client*> liste_client, std::vector<Commande*> liste_commande) {
	m_produit = liste_produit;
	m_client = liste_client;
	m_commande = liste_commande;
}



void Magasin::ajouterProduit(Produit *produit){
	m_produit.push_back(produit);
}


void Magasin::afficherListeProduit(){

	std::string res = "";
	int taille = m_produit.size();

	for(int i=0; i<taille; i++)
	{
		res += (*m_produit[i]).getTitre()+"\n";
		res += std::to_string((*m_produit[i]).getPrix())+"\n";
		res += (*m_produit[i]).getDetail()+"\n";
		res += std::to_string((*m_produit[i]).getQuantite())+"\n";
	}

	if(res=="")
	{
		std::cout<<"Il n'y a pas de produit dans le magasin"<<std::endl;
	}else{
		std::cout<<res<<std::endl;
	}
}

void Magasin::afficherProduit(Produit *produit){

	int taille = m_produit.size();
	std::string res="";

	for(int i=0; i<taille; i++)
	{
		if(m_produit[i] == produit)
		{
			res +=(*m_produit[i]).getTitre()+"\n";
			res +=std::to_string((*m_produit[i]).getPrix())+"\n";
			res +=(*m_produit[i]).getDetail()+"\n";
			res +=std::to_string((*m_produit[i]).getQuantite())+"\n";
		}
	}

	std::cout<<res<<std::endl;

}

void Magasin::quantiteProduit(Produit *produit,double quantite){

	std::string res="";
	int taille = m_produit.size();

	for(int i=0; i<taille; i++)
	{
		if(m_produit[i] == produit)
		{
			(*m_produit[i]).setQuantite(quantite);
		}
	}
}


void Magasin::ajouterClient(Client *client){
	m_client.push_back(client);
}

void Magasin::afficherListeClient(){
	std::string res = "";
	int taille = m_client.size();

	for(int i=0; i<taille; i++){
		res += "ID : "+std::to_string((*m_client[i]).getId())+"\n";
		res +=(*m_client[i]).getNom()+"\n";
		res +=(*m_client[i]).getPrenom()+"\n";
	}

	if(res=="")
	{
		std::cout<<"Il n'y a pas de client dans le magasin"<<std::endl;
	}else {
		std::cout<<res<<std::endl;
	}

}

void Magasin::afficherClient(std::string nom, int id) {
	int taille = m_client.size();
	if(taille == 0) {
		std::cout<<"Il n'y a pas de client dans le magasin"<<std::endl;
	}else{
		for(int i=0; i<taille; i++) {
			if(((*m_client[i]).getNom() == nom) || ((*m_client[i]).getId() == id))
			{
				std::string res = "";
				res += "ID : "+std::to_string((*m_client[i]).getId())+"\n";
				res +=(*m_client[i]).getNom()+"\n";
				res +=(*m_client[i]).getPrenom()+"\n";

				std::cout<<res<<std::endl;
			}
		}
	}
}

void Magasin::ajouterProduitClient(Produit *produit, Client *client) {
	int taille = m_client.size();

	if(taille == 0){
		std::cout<<"Il n'y a pas de client dans le magasin"<<std::endl;
	}else{
		for(int i=0; i<taille; i++){
			if((*m_client[i]).getNom() == client->getNom()){
				(*m_client[i]).ajouterProduit(produit);
			}
		}
	}
}

void Magasin::supprimerProduitClient(Produit *produit, Client *client) {
	int taille = m_client.size();

	if(taille == 0){
		std::cout<<"Il n'y a pas de client dans le magasin"<<std::endl;
	}else{
		for(int i=0; i<taille; i++){
			if((*m_client[i]).getNom() == client->getNom()){
				(*m_client[i]).supprimerProduit(produit);
			}
		}
	}

}

void Magasin::modifierQuantiteProduitClient(Produit *produit, Client *client, double quantite){
	int taille = m_client.size();

		if(taille == 0){
			std::cout<<"Il n'y a pas de client dans le magasin"<<std::endl;
		}else{
			for(int i=0; i<taille; i++){
				if((*m_client[i]).getNom() == client->getNom()){
					(*m_client[i]).changerQuantite(produit,quantite);
				}
			}
		}
}

std::vector<Produit*> Magasin::getProduit() const {
	return m_produit;
}

std::vector<Client*> Magasin::getClient() const {
	return m_client;
}

std::vector<Commande*> Magasin::getCommande() const {
	return m_commande;
}


