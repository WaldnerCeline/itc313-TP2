/**
* File :	produit.h
* Author :	Celine Waldner  (WaldnerCeline -> github)
* Date :	Fall 2019
* Course: 	C-C++ Programming / Esirem 3A Informatique Electronique
* Summary :	Definition of the class Produit
*/

#include "produit.h"
#include <iostream>
 
Produit::Produit(std::string titre, std::string detail, double prix, double quantite){
	m_titre = titre;
	m_detail = detail;
	if(quantite >=0){
		m_quantite = quantite;
	}
	else{
		std::cout << "Erreur de quantite"<<std::endl;
	}
	if(prix >=0){
		m_prix = prix;
	}
	else{
		std::cout<< "Prix incorrect"<< std::endl;
	}
}

std::string Produit::getTitre() const{
	return m_titre;
}

std::string Produit::getDetail() const{
	return m_detail;
}

double Produit::getQuantite() const{
	return m_quantite;
}

double Produit::getPrix() const{
	return m_prix;
}


void Produit::setTitre(std::string titre){
	m_titre = titre;
}

void Produit::setDetail(std::string detail){
	m_detail = detail;
}

void Produit::setQuantite(double quantite){
	if(quantite >=0){
		m_quantite = quantite;
	}
	else{
		std::cout << "Erreur de quantite"<<std::endl;
	}
}

void Produit::setPrix(double prix){
	if(prix >=0){
		m_prix = prix;
	}
	else{
		std::cout<< "Prix incorrect"<< std::endl;
	}
}

void Produit::modifQuantite(double quantite){
	if(quantite >=0){
		m_quantite = quantite;
	}
	else{
		std::cout<< "Prix incorrect"<< std::endl;
	}
}


std::ostream& operator << (std::ostream & output, Produit obj){
	output << obj.m_titre << std::endl << obj.m_detail << std::endl << "Prix unitaire : " << obj.m_prix<< std::endl << "Quantite restante : "<< obj.m_quantite << std::endl;
	return output;
}





