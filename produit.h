/**
* File :	produit.h
* Author :	Celine Waldner  (WaldnerCeline -> github)
* Date :	Fall 2019
* Course: 	C-C++ Programming / Esirem 3A Informatique Electronique
* Summary :	Definition of the class Product
*/



#ifndef PRODUIT_H
#define PRODUIT_H
#include <string>
#include <iostream>

class Produit {
public:
	Produit(std::string titre, std::string detail, double prix, double quantite);
	std::string getTitre() const;
	std::string getDetail() const;
	double getQuantite() const;
	double getPrix() const;

	void setTitre(std::string titre);
	void setDetail(std::string detail);
	void setQuantite(double quantite);
	void setPrix(double prix);
	void modifQuantite(double quantite);

	friend std::ostream& operator << (std::ostream &output, Produit obj);

private:
	std::string m_titre;
	std::string m_detail;
	double m_quantite;
	double m_prix;
	


};

#endif //PRODUIT_H