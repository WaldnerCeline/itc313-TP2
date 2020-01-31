#ifndef _magasin_h
#define _magasin_h

#include "client.h"
#include "produit.h"
#include "commande.h"

#include <vector>
#include <string>
class Magasin {

public:
	Magasin(std::vector<Produit*> liste_produit,
		std::vector<Client*> liste_client,
		std::vector<Commande*> liste_commande);

	void ajouterProduit(Produit *produit);
	void afficherListeProduit();
	void afficherProduit(Produit *produit);
	void quantiteProduit(Produit *produit, double quantite);


	void ajouterClient(Client *client);
	void afficherListeClient();
	void afficherClient(std::string nom, int id);

	void ajouterProduitClient(Client *client, Produit *produit, double quantite);
	void supprimerProduitClient(Produit *produit, Client *client);
	void modifierQuantiteProduitClient(Produit *produit, Client *client, double quantite);
	void validerCommande(Client *client);
	void changerStatutCommande(int id);
	void afficherListeCommande();
	void afficherListeCommandeClient(Client *client);

	std::vector<Produit*> getProduit()const;
	std::vector<Client*> getClient()const;
	std::vector<Commande*> getCommande()const;

private :
	std::vector<Produit*> m_produit;
	std::vector<Client*> m_client;
	std::vector<Commande*> m_commande;
};
#endif
