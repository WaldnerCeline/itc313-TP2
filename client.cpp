#include "client.h"
#include <string>
#include <vector>
#include <iostream>

Client::Client(int id, std::string nom, std::string prenom, std::vector<Produit*> panier){
	m_id = id;
	m_nom = nom;
	m_prenom = prenom;
	m_panier = panier;
}


int Client::getId() const {
	return m_id;
}

std::string Client::getNom()const {
	return m_nom;
}

std::string Client::getPrenom()const{
	return m_prenom;
}


std::vector<Produit*> Client::getPanier()const{
	return m_panier;
}

double getQuantiteCommande() const{
	return m_quantite_commande;
}

void Client::ajouterProduit(Produit *produit, double quantite_commande){

	if ((*produit).getQuantite() >= quantite_commande){
		 m_quantite_commande = quantite_commande;
		 m_panier.push_back(produit);
	}
	else{
		std::cout <<"Il n'y a pas assez d'articles en stock";
	}

}


void Client::viderPanier() {
	int taille = m_panier.size();
	for(int i=0; i<taille; i++)
	{
		m_panier[i] = nullptr;
		m_panier.resize(0);
	}
}


void Client::changerQuantite(Produit *produit, double quantite_commande){
	int taille =  m_panier.size();
	for(int i=0; i<taille; i++){

		if(m_panier[i] == produit)
		{
		 if (produit.getQuantite() >= quantite_commande){
		 	m_quantite_commande = quantite_commande;
		 }
		 else{
		 	std::cout <<"Il n'y a pas assez d'articles en stock";
		 }
		}
		else{
			std::cout << "Cet article n'est pas dans votre panier";
		}
		

	}
}

void Client::supprimerProduit(Produit *produit){
	int taille = m_panier.size();

	for(int i=0; i<taille; i++)
	{
		if(m_panier[i] == produit)
		{
			m_panier[i] = nullptr;
			std::cout<<"Le produit à été supprimé"<<std::endl;
			m_panier.resize(taille-1);
		}
	}
}

std::string Client::recupPanier() {
	std::string res="";
	int taille = m_panier.size();

	for(int i=0; i<taille; i++)
	{
		res += "Nom article : "+(*m_panier[i]).getTitre()+"	";
		res += "Quantité : "+std::to_string((*m_panier[i]).getQuantite())+"	";
		res += "Prix Unitaire : "+std::to_string((*m_panier[i]).getPrix())+"\n";
	}

	if(res=="")
	{
		res = "Le panier est vide";
	} 
	return res;
}



std::ostream& operator << (std::ostream & output, Client obj){

	output << obj.m_id << std::endl << obj.m_nom << std::endl << obj.m_prenom << std::endl<< obj.recupPanier() << std::endl;
	return output;
}
