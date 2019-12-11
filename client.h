
#ifndef _client_h
#define _client_h


#include "produit.h"
#include <string>
#include <vector>
#include <iostream>

class Client {


public:
	Client(int id, std::string nom, std::string prenom, std::vector<Produit*> panier);

	int getId()const;
	std::string getNom()const;
	std::string getPrenom()const;
	std::vector<Produit*> getPanier()const;

	void ajouterProduit(Produit *produit);
	void viderPanier();
	void supprimerProduit(Produit *produit);

	friend std::ostream& operator << (std::ostream &output, Client obj);
private:
	int m_id;
	std::string m_nom;
	std::string m_prenom;
	std::vector<Produit*> m_panier;
};
#endif
