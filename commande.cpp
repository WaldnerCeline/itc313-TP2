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

Commande::Commande(/*Client* client_commande,*/std::vector<Produit*> produit_commande, bool statut_commande){
	//m_client_commande = client_commande;
	m_produit_commande = produit_commande;
	m_statut_commande = statut_commande;
 }
/*Client* Commande::getClientCommande() const{
	return m_client_commande;
}*/

std::vector<Produit*> Commande::getProduitCommande() const{
	return m_produit_commande;
}

std::string Commande::getStatutCommande() const{
	std::string statut;
	if(m_statut_commande == true){
		statut = "Livré";
	}
	else{
		statut = "Non Livré";
	}
	return statut;
}


/*void Commande::setClientCommande(Client* client_commande){
	m_client_commande = client_commande;
}*/

void Commande::setProduitCommande(std::vector<Produit*> produit_commande){
	m_produit_commande = produit_commande;
}

void Commande::setStatutCommande(bool statut_commande){
	m_statut_commande = statut_commande;
}


std::string Commande::recupListeProduit() const{
	std::string affichage;
	int taille =  m_produit_commande.size();
	for(int i=0 ; i< taille; i++){
		affichage += (*m_produit_commande[i]).getTitre() + "\n " + (*m_produit_commande[i]).getDetail() + "\n  Prix unitaire : " + std::to_string((*m_produit_commande[i]).getPrix()) + "\n  Quantite restante : "+  std::to_string((*m_produit_commande[i]).getQuantite()) + "\n" + "\n";  
	}
	return affichage;
}

std::string Commande::recupInfoClient() const{
	std::string affichage;
	affichage = 
	
}





std::ostream& operator << (std::ostream & output, Commande liste_commande){
	output << "Panier :\n" << liste_commande.recupListeProduit()+ "\n Statut de la commande : " << liste_commande.getStatutCommande() << std::endl;
	return output;
}

