/**
* File :	commandecpp
* Author :	Celine Waldner  (WaldnerCeline -> github)
* Date :	Fall 2019
* Course: 	C-C++ Programming / Esirem 3A Informatique Electronique
* Summary :	Definition of the class Commande
*/

#include "commande.h"
#include <iostream>
#include <vector>
#include "client.h"
#include "produit.h"

Commande::Commande(Client* client_commande,std::vector<Produit*> produit_commande, bool statut_commande){
	m_id = 0;
	m_client_commande = client_commande;
	m_produit_commande = produit_commande;
	m_statut_commande = statut_commande;
 }

Client* Commande::getClientCommande() const{
	return m_client_commande;
}

int Commande::getIDCommande() const{
	return m_id;
}

std::vector<Produit*> Commande::getProduitCommande() const{
	return m_produit_commande;
}

std::string Commande::getStatutCommande() const{
	std::string statut;
	if(m_statut_commande == true){
		statut = "Livrée";
	}
	else{
		statut = "Non Livrée";
	}
	return statut;
}


void Commande::setClientCommande(Client* client_commande){
	m_client_commande = client_commande;
}

void Commande::setProduitCommande(std::vector<Produit*> produit_commande){
	m_produit_commande = produit_commande;
}

void Commande::setStatutCommande(bool statut_commande){
	m_statut_commande = statut_commande;
}

void Commande::setIDCommande(int id){
	m_id = id;
}

std::string Commande::recupListeProduit() const{
	std::string affichage;
	double prix;
	int taille =  m_produit_commande.size();
	for(int i=0 ; i< taille; i++){
		prix += ((*m_produit_commande[i]).getQuantiteCommande())*((*m_produit_commande[i]).getPrix());
		affichage += (*m_produit_commande[i]).getTitre() + "\n " + (*m_produit_commande[i]).getDetail() + "\n  Prix unitaire : " + std::to_string((*m_produit_commande[i]).getPrix()) + "\n  Quantite : "+  std::to_string((*m_produit_commande[i]).getQuantiteCommande()) + "\n" + "\n";  
	}
	affichage+= "Prix total de la commande : " +std::to_string(prix) +"\n";
	return affichage;
}

std::string Commande::recupInfoClient() const{
	std::string affichage;
	affichage = "ID client " + std::to_string((*m_client_commande).getId()) + "\n" + (*m_client_commande).getNom() + " " + (*m_client_commande).getPrenom() +"\n";
	
return affichage;
}





std::ostream& operator << (std::ostream & output, Commande liste_commande){
	output << liste_commande.recupInfoClient() + "\n" + "Contenu de la commande : " + "\n" << liste_commande.recupListeProduit()+ "\nStatut de la commande : " << liste_commande.getStatutCommande() << std::endl;
	return output;
}

