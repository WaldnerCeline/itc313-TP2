#ifndef _magasin_h
#define _magasin_h

#include "Client.h"
#include "Produit.h"
#include "Commande.h"

#include <vector>
#include <string>
class Magasin {

public:
	Magasin(std::vector<Produit*> liste_produit,
		std::vector<Client*> liste_client,
		std::vector<Commande*> liste_commande);

	void addProduit(Produit produit);
	std::string afficherListeProduit();

	std::vector getProduit()const;
	std::vector getClient()const;
	std::vector getCommande()const;

private :
	std::vector<Produit*> m_produit;
	std::vector<Client*> m_client;
	std::vector<Commande*> m_commande;
};
#endif
