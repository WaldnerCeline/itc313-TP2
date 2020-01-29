/**
* File :	commande.h
* Author :	Celine Waldner  (WaldnerCeline -> github)
* Date :	Fall 2019
* Course: 	C-C++ Programming / Esirem 3A Informatique Electronique
* Summary :	Definition of the class Commande
*/



#ifndef COMMANDE_H
#define COMMANDE_H
#include <string>
#include <iostream>
#include <vector>
#include "client.h"
#include "produit.h"




class Commande {
public:
	Commande(Client* client_commande,std::vector<Produit*> produit_commande, bool statut_commande);
	Client* getClientCommande() const;
	std::vector<Produit*> getProduitCommande() const;
	std::string getStatutCommande() const;

	void setClientCommande(Client* client_commande);
	void setProduitCommande(std::vector<Produit*> produit_commande);
	void setStatutCommande(bool statut_commande);

	std::string recupListeProduit() const;
	std::string recupInfoClient() const;

	friend std::ostream& operator << (std::ostream &output, Commande com);

private:
	Client* m_client_commande;
	std::vector<Produit*> m_produit_commande;
	bool m_statut_commande;




	


};

#endif //COMMANDE_H