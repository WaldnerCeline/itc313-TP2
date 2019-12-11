#include "client.h"
#include <string>
#include <vector>

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


void Client::ajouterProduit(Produit *produit){
	m_panier.push_back(produit);
}


void Client::viderPanier() {
	m_panier.clear();
}

void Client::supprimerProduit(Produit *produit){
	//m_panier.erase(produit);
}

std::ostream& operator << (std::ostream & output, Client obj){
	output << obj.m_id << std::endl << obj.m_nom << std:: endl << obj.m_prenom << std::endl;// << obj.m_panier << std::endl;
	return output;
}
