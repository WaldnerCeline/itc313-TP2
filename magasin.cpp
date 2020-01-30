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
	std::cout<<std::endl;
	std::cout<<"Inventaire du magasin"<<std::endl;
	std::cout<<std::endl;
	for(int i=0; i<taille; i++)
	{
		res +=(*m_produit[i]).getTitre()+"\n";
		res +=(*m_produit[i]).getDetail()+"\n";
		res += "Prix unitaire : " + std::to_string((*m_produit[i]).getPrix())+"\n";
		res += "Quantite restante : " +std::to_string((*m_produit[i]).getQuantite())+"\n";
		res +="\n";
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
			res +=(*m_produit[i]).getDetail()+"\n";
			res += "Prix unitaire : " + std::to_string((*m_produit[i]).getPrix())+"\n";
			res += "Quantite restante : " +std::to_string((*m_produit[i]).getQuantite())+"\n";
			res +="\n";
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
		else{
			std::cout<<" Aucun produit correspondant "<<std::endl;
		}
	}
}


void Magasin::ajouterClient(Client *client){
	m_client.push_back(client);
}

void Magasin::afficherListeClient(){
	std::string res = "";
	int taille = m_client.size();
	std::cout<<std::endl;
	std::cout<<"Liste des clients"<<std::endl;
	std::cout<<std::endl;
	for(int i=0; i<taille; i++){
		res += "ID client : "+std::to_string((*m_client[i]).getId())+"\n";
		res +=(*m_client[i]).getNom()+" " + (*m_client[i]).getPrenom()+"\n";
		res +="\n";
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
				res += "ID client: "+std::to_string((*m_client[i]).getId())+"\n";
				res +=(*m_client[i]).getNom()+" " + (*m_client[i]).getPrenom()+"\n";
				res +="\n";

				std::cout<<res<<std::endl;
			}
		}
	}
}

void Magasin::ajouterProduitClient(Client *client, Produit *produit, double quantite) {
	int taille = m_client.size();

	if(taille == 0){
		std::cout<<"Il n'y a pas de client dans le magasin"<<std::endl;
	}else{
		for(int i=0; i<taille; i++){
			if((*m_client[i]).getNom() == client->getNom()){
				(*m_client[i]).ajouterProduit(produit, quantite);
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
					(*m_client[i]).changerQuantiteCommande(produit,quantite);
				}
			}
		}
}


int Magasin::validerCommande(Client *client){
	std::vector<Produit*> commande_client;
	commande_client = (*client).getPanier();
	int taille = m_client.size();
	int taille_commande = commande_client.size();
	int id= 0;
	if(taille_commande != 0){
		Commande commande1(client, commande_client, false);
		Commande *ref_commande;
		ref_commande = &commande1;
		id = m_commande.size()+1;
		commande1.setIDCommande(id);
		m_commande.push_back(ref_commande);
		for(int i=0; i<taille; i++) {
			if((*client).getNom()!= (*m_client[i]).getNom() ){
				ajouterClient(client);
			}	
		}
	}
	else{
		std::cout<<"Le panier est vide, impossible de valider la commande"<<std::endl;
	}
return id;
}

void Magasin::changerStatutCommande(Commande *commande){
	int taille = m_commande.size();
	int choix;
	for(int i =0; i < taille; i++){
		if((*commande).getIDCommande() == (*m_commande[i]).getIDCommande()){
			std::string statut = (*(m_commande[i])).getStatutCommande();
			std::cout<<"Cette commande est "<< statut << std::endl;
			do{
				std::cout<<" 1 - Mettre le statut a Livree "<<std::endl;
				std::cout<<" 2 - Mettre le statut a Non Livree"<<std::endl;
				std::cout<< "Entrez votre choix"<< std::endl;
				std::cin >> choix;
				switch (choix) {
					case 1 :
						(*m_commande[i]).setStatutCommande(true);
						break;
					case 2 :
						(*m_commande[i]).setStatutCommande(false);
						break;
				}
			}
			while(choix != 1 || choix != 2);
		}
		else{
			std::cout<< "Aucune commande ne correspond"<<std::endl;
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


