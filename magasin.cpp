#include "magasin.h"
#include "client.h"
#include "commande.h"
#include "produit.h"

#include <vector>
#include <string>


Magasin::Magasin(std::vector<Produit*> liste_produit, std::vector<Client*> liste_client, std::vector<Commande*> liste_commande) {
	m_produit = liste_produit;
	m_client = liste_client;
	m_commande = liste_commande;
}



void Magasin::ajouterProduit(Produit *produit){ // on ajoute un produit au stock du magasin
	m_produit.push_back(produit);
	
}


void Magasin::afficherListeProduit(){ //affichage de la liste des produits du magasin

	std::string res = "";
	int taille = m_produit.size();
	std::cout<<"Taille mproduit" << taille <<std::endl;
	std::cout<<" Inventaire du magasin "<<std::endl;
	std::cout<<std::endl;
	for(int i=0; i< int(m_produit.size()); i++){
		std::cout<<"verif 2 "<< (*m_produit[i])<< std::endl;
	}
	for(int i=0; i<taille; i++)
	{
		res +=" "+(*m_produit[i]).getTitre()+"\n";
		res +=" "+(*m_produit[i]).getDetail()+"\n";
		res += " Prix unitaire : " + std::to_string((*m_produit[i]).getPrix())+"\n";
		res += " Quantite restante : " +std::to_string((*m_produit[i]).getQuantite())+"\n";
		res +="\n";
	}

	if(res=="")
	{
		std::cout<<" Il n'y a pas de produit dans le magasin"<<std::endl;
	}else{
		std::cout<<res<<std::endl;
	}
}

void Magasin::afficherProduit(Produit *produit){ // affichage des infos d'un objet

	int taille = m_produit.size();
	std::string res="";

	for(int i=0; i<taille; i++)
	{
		if(m_produit[i] == produit)
		{
			res +=" "+(*m_produit[i]).getTitre()+"\n";
			res +=" "+(*m_produit[i]).getDetail()+"\n";
			res += " Prix unitaire : " + std::to_string((*m_produit[i]).getPrix())+"\n";
			res += " Quantite restante : " +std::to_string((*m_produit[i]).getQuantite())+"\n";
			res +="\n";
		}
	}

	std::cout<<res<<std::endl;

}

void Magasin::quantiteProduit(Produit *produit,double quantite){ //changer la quantite dans le stock du magasin d'un objet donne 

	std::string res="";
	int taille = m_produit.size();

	for(int i=0; i<taille; i++)
	{
		if(m_produit[i] == produit)
		{
			(*m_produit[i]).setQuantite(quantite);
		}
		else{
			std::cout<<" Aucun produit correspondant "<<std::endl;
		}
	}
}


void Magasin::ajouterClient(Client *client){ // ajouter un nouveau client au magasin
	m_client.push_back(client);
}

void Magasin::afficherListeClient(){ // afficgher la liste de clients
	std::string res = "";
	int taille = m_client.size();
	std::cout<<std::endl;
	std::cout<<" Liste des clients"<<std::endl;
	std::cout<<std::endl;
	for(int i=0; i<taille; i++){
		res += " ID client : "+std::to_string((*m_client[i]).getId())+"\n";
		res +=" "+(*m_client[i]).getNom()+" " + (*m_client[i]).getPrenom()+"\n";
		res +="\n";
	}

	if(res=="")
	{
		std::cout<<" Il n'y a pas de client dans le magasin"<<std::endl;
	}else {
		std::cout<<res<<std::endl;
	}

}

void Magasin::afficherClient(std::string nom, int id) { // afficher les informations d'un client donné
	int taille = m_client.size();
	if(taille == 0) {
		std::cout<<" Il n'y a pas de client dans le magasin"<<std::endl;
	}else{
		for(int i=0; i<taille; i++) {
			if(((*m_client[i]).getNom() == nom) || ((*m_client[i]).getId() == id))
			{
				std::string res = "";
				res += " ID client: "+std::to_string((*m_client[i]).getId())+"\n";
				res +=" "+(*m_client[i]).getNom()+" " + (*m_client[i]).getPrenom()+"\n";
				res +="\n";

				std::cout<<res<<std::endl;
			}
		}
	}
}

void Magasin::ajouterProduitClient(Client *client, Produit *produit, double quantite) { // ajout d'un produit au panier du client
	int taille = m_client.size();

	if(taille == 0){
		std::cout<<" Il n'y a pas de client dans le magasin"<<std::endl;
	}else{
		for(int i=0; i<taille; i++){
			if((*m_client[i]).getNom() == client->getNom()){
				(*m_client[i]).ajouterProduit(produit, quantite);
			}
		}
	}
}

void Magasin::supprimerProduitClient(Produit *produit, Client *client) { //suppriler un produit du panier d'un client
	int taille = m_client.size();

	if(taille == 0){
		std::cout<<" Il n'y a pas de client dans le magasin"<<std::endl;
	}else{
		for(int i=0; i<taille; i++){
			if((*m_client[i]).getNom() == client->getNom()){
				(*m_client[i]).supprimerProduit(produit);
			}
		}
	}

}

void Magasin::modifierQuantiteProduitClient(Produit *produit, Client *client, double quantite){ // modifier la quantite d'un produit dans le panier client
	int taille = m_client.size();

		if(taille == 0){
			std::cout<<" Il n'y a pas de client dans le magasin"<<std::endl;
		}else{
			for(int i=0; i<taille; i++){
				if((*m_client[i]).getNom() == client->getNom()){
					(*m_client[i]).changerQuantiteCommande(produit,quantite);
				}
			}
		}
}


void Magasin::validerCommande(Client *client){ // valider la panier d'un client pour le transformer en commande
	std::vector<Produit*> commande_client;
	commande_client = (*client).getPanier();
	int taille = m_client.size();
	int taille_commande = commande_client.size();
	int id= 0;
	int compteur =0;
		Commande* ref_commande(0); //declaration d'un pointeur sur une commande
		ref_commande = new Commande (client, commande_client, false);
		id = m_commande.size()+1;
		(*ref_commande).setIDCommande(id);
		m_commande.push_back(ref_commande);
		taille_commande = commande_client.size();
		for(int i=0; i<taille; i++) {
			if((*client).getNom()!= (*m_client[i]).getNom() ){ // on regarde si le client fait deja partie du magasin, si non, on l'ajoute
				compteur++;
			}	
		}
		if(compteur == taille){
		ajouterClient(client);
		}
	if(taille_commande == 0){
		std::cout<<" Le panier est vide, impossible de valider la commande"<<std::endl;
	}
}

void Magasin::changerStatutCommande(int id){ //On livre la commande
	int taille = m_commande.size();
	int id_commande;
	int compteur;
	double quantite_commande;
	std::string statut;
	for(int i =0; i < taille; i++){
		id_commande = (*m_commande[i]).getIDCommande();
		if(id  == id_commande){
			compteur++;
			statut = (*(m_commande[i])).getStatutCommande();
			if(statut == "Livrée"){
				std::cout<< " Cette commande est dejà livrée "<<std::endl;
			}
			else{
				// modifier les quantite en stock pour livrer la commande
				std::vector<Produit*> liste_produit;
				liste_produit = (*m_commande[i]).getProduitCommande();
				for(int j=0; j < int(liste_produit.size()); j++){
					 quantite_commande = (*liste_produit[j]).getQuantiteCommande();
					 (*liste_produit[j]).modifQuantite( -quantite_commande);
					 (*m_commande[i]).setStatutCommande(true);
				}

			}
		}
	}
	if(compteur == 0){
			std::cout<< " Aucune commande ne correspond"<<std::endl;		
	}
}


std::vector<Produit*> Magasin::getProduit() const {
	return m_produit;
}

std::vector<Client*> Magasin::getClient() const {
	return m_client;
}

std::vector<Commande*> Magasin::getCommande() const {
	return m_commande;
}

void Magasin::afficherListeCommande(){ // afficgher la liste de commande
	int taille = m_commande.size();
	std::cout<<std::endl;
	std::cout<<" Liste des commandes"<<std::endl;
	std::cout<<std::endl;
	if(taille != 0){
		for(int i=0; i<taille; i++){
			std::cout<< " ID commande : " << (*m_commande[i]).getIDCommande() <<std::endl;
			std::cout<<std::endl;
			std::cout<< (*m_commande[i]).recupInfoClient() <<std::endl;
			std::cout<< " Contenu de la commande "<<std::endl;
			std::cout<< (*m_commande[i]).recupListeProduit() <<std::endl;
			std::cout<< " Statut de le commande : " << (*m_commande[i]).getStatutCommande()<<std::endl;
		}
	}
	else{
		std::cout<< " Il n'y a pas de commande"<< std::endl;
		std::cout<<std::endl;
	}
}

void Magasin::afficherListeCommandeClient(Client *client){ // afficgher la liste de commande d'un client
	Client *client_commande;
	std::vector<Commande*> temp;
	std::cout<<" Liste des commandes"<<std::endl;
	std::cout<<std::endl;
	int taille = m_commande.size();
	if(taille != 0){
		for(int j =0; j< int(m_commande.size()); j++){
			client_commande = (*m_commande[j]).getClientCommande();
			if((*client).getId() == (*client_commande).getId()){ //on verifie que le client fait partie des clients
				std::cout<< " ID client : " << (*client_commande).getId() <<std::endl;
				std::cout << " " << (*client_commande).getNom() << " " << (*client_commande).getPrenom() <<std::endl;
				std::cout<<std::endl;
				temp.push_back(m_commande[j]); // on stocke toutes les commandes d'un client
			}
			
		}
		for(int i=0; i<int(temp.size()); i++){
			std::cout<<std::endl;	
			std::cout<< " ID commande : " << (*temp[i]).getIDCommande() <<std::endl;
			std::cout<<std::endl;
			std::cout<< " Contenu de la commande "<<std::endl;
			std::cout<< (*temp[i]).recupListeProduit() <<std::endl;
			std::cout<< " Statut de le commande : " << (*temp[i]).getStatutCommande()<<std::endl;
		}
		if(int(temp.size()) == 0){
			std::cout<<std::endl;
			std::cout<<" Auncun client correspondant "<<std::endl;
			std::cout<<std::endl;
		}
	}
	else{
		std::cout<<std::endl;
		std::cout<< " Il n'y a pas de commande"<< std::endl;
		std::cout<<std::endl;
	}
}

