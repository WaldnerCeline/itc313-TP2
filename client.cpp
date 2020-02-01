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

void Client::setId(int id) {
	m_id = id;
}

void Client::setNom(std::string nom) {
	 m_nom= nom;
}

void Client::setPrenom(std::string prenom){
	m_prenom = prenom;
}


void Client::ajouterProduit(Produit *produit, double quantite_commande){ // ajout d'un prdoduit au panier
	(*produit).setQuantiteCommande(quantite_commande);
	m_panier.push_back(produit);
}


void Client::viderPanier() {
	int taille = m_panier.size();
	for(int i=0; i<taille; i++)
	{
		m_panier[i] = nullptr;
		m_panier.resize(0);
	}
}


void Client::changerQuantiteCommande(Produit *produit, double quantite_commande){ //modifier la quantite d'un produit a commander
	int taille =  m_panier.size();
	int compteur =0;
	for(int i=0; i<taille; i++){
		
			if(m_panier[i] == produit){
				(*(m_panier[i])).setQuantiteCommande(quantite_commande);
				compteur ++;
			}
		
			else if(compteur == 0){
				std::cout << " Cet article n'est pas dans votre panier ";
			}
	}
}

void Client::supprimerProduit(Produit *produit){ //supprimer un produit du panier
	int taille = m_panier.size();

	for(int i=0; i<taille; i++)
	{
		if(m_panier[i] == produit)
		{
			m_panier[i] = nullptr;
			std::cout<<" Le produit à été supprimé"<<std::endl;
			m_panier.resize(taille-1);
		}
	}
}

std::string Client::recupPanier() { // pour l'affichage du panier
	std::string res="";
	int taille = m_panier.size();
	double prix=0;
	int compteur =0;
	std::cout<<" Le panier contient : "<<std::endl;
	for(int i=0; i<taille; i++){
		compteur++;
		res += " Nom article : "+(*m_panier[i]).getTitre()+"	";
		res += " Quantité : "+std::to_string((*m_panier[i]).getQuantiteCommande())+"	";
		res += " Prix Unitaire : "+std::to_string((*m_panier[i]).getPrix())+"\n";
		prix += ((*m_panier[i]).getQuantiteCommande())*((*m_panier[i]).getPrix());
	}
	if(compteur != 0){
		res += " Le prix total du panier est : "+std::to_string(prix);
	}
	if(res=="")
	{
		res = " Le panier est vide";
	} 
	return res;
}



std::ostream& operator << (std::ostream & output, Client obj){ //surcharge de cout

	output << " ID client " << obj.m_id << std::endl << " "<<obj.m_nom << " " << obj.m_prenom << std::endl<< obj.recupPanier() << std::endl;
	return output;
}
