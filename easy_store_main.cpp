/**
* File :	easy_store_main.cpp
* Author :	Celine Waldner  (WaldnerCeline -> github)
* Date :	Fall 2019
* Course: 	C-C++ Programming / Esirem 3A Informatique Electronique
* Summary :	Main file
*/

#include<iostream>
#include "magasin.h"
#include <vector>
#include <string>
#include "produit.h"
#include "commande.h"
#include "client.h"
#include <iostream>
#include <fstream>
#include <cstdlib>


void ecriture_fichier_Produit(Magasin EasyStore){
    std::string const fichier_produit("produit.txt");
    std::ofstream monFlux(fichier_produit.c_str());
    std::vector<Produit*> produit;
    produit = EasyStore.getProduit();
    if(monFlux){
    	monFlux << " Inventaire du magasin "<<std::endl;
    	monFlux << std::endl;
       for(int i = 0; i< int(produit.size()); i++){
       	monFlux << (*produit[i]);
       	monFlux << std::endl;
     	 }
     }
    
    else
    {
        std::cout << " ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

 


void lecture_fichier_Produit(){
   std::ifstream fichier_produit("produit.txt");

   if(fichier_produit){
      //L'ouverture s'est bien passée, on peut donc lire
	std::string ligne; //Une variable pour stocker les lignes lues

    while(getline(fichier_produit, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
        std::cout << ligne << std::endl;
         //Et on l'affiche dans la console
      }
   }
   else{
      std::cout << " ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
   }

}

void ecriture_fichier_Client(Magasin EasyStore){
    std::string const fichier_client("client.txt");
    std::ofstream monFlux(fichier_client.c_str());
    std::vector<Client*> client;
    client = EasyStore.getClient();

    if(monFlux){
      	monFlux << " Liste des clients "<<std::endl;
      	monFlux << std::endl;
       for(int i = 0; i< int(client.size()); i++){
       	monFlux << "  client : " << (*client[i]).getId()<<std::endl;
       	monFlux << " " << (*client[i]).getNom()<< " " << (*client[i]).getPrenom() << std::endl;
       	monFlux << std::endl;
     	}
     
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

 


void lecture_fichier_Client(){
   std::ifstream fichier_client("client.txt");

   if(fichier_client){
      //L'ouverture s'est bien passée, on peut donc lire
	std::string ligne; //Une variable pour stocker les lignes lues

    while(getline(fichier_client, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
        std::cout << ligne << std::endl;
         //Et on l'affiche dans la console
      }
   }
   else{
      std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
   }

}
void ecriture_fichier_Commande(Magasin EasyStore){
    std::string const fichier_commande("commande.txt");
    std::ofstream monFlux(fichier_commande.c_str());
    std::vector<Commande*> commande;
    commande = EasyStore.getCommande();

    if(monFlux){
       monFlux << " Liste des commandes "<<std::endl;
       monFlux << std::endl;
       for(int i = 0; i< int(commande.size()); i++){
       monFlux << (*commande[i]);
       monFlux << std::endl;
     	}
    }
    else
    {
        std::cout << " ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

 


void lecture_fichier_Commande(){
   std::ifstream fichier_commande("commande.txt");

   if(fichier_commande){
      //L'ouverture s'est bien passée, on peut donc lire
	std::string ligne; //Une variable pour stocker les lignes lues

    while(getline(fichier_commande, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
        std::cout << ligne << std::endl;
         //Et on l'affiche dans la console
      }
   }
   else{
      std::cout << " ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
   }

}


void ajoutProduit(Magasin EasyStore){
	std::string titre;
	std::string detail;
	double prix;
	double quantite;
	std::cout<<" Entrez le nom du nouveau produit : "<<std::endl;
	std::cin>> titre;
	std::cout<<std::endl;
	std::cout<< " Quel est le detail de ce produit (en un seul mot) : "<<std::endl;
	std::cin>> detail;
	std::cout<<std::endl;
	std::cout<<" Entrez le prix unitaire du produit : "<<std::endl;
	std::cin>>prix;
	std::cout<<std::endl;
	std::cout<<" Entrez la quantite a mettre en stock : "<<std::endl;
	std::cin>>quantite;
	std::cout<<std::endl;
	Produit *ref_produit1(0); //declaration d'un pointeur sur un objet
	ref_produit1 = new Produit (titre, detail, prix, quantite);
	EasyStore.ajouterProduit(ref_produit1);
	std::vector<Produit*> produit;
}



void majQuantite(Magasin EasyStore){
	double quantite;
	std::string nom;
	int compteur=0;
	std::vector<Produit*> produit;
	produit = EasyStore.getProduit();
	std::cout<<" Entrez le nom du produit a modifier "<<std::endl;
	std::cin>> nom;
	for(int i = 0; i<int(produit.size()); i++){
		if( nom == (*produit[i]).getTitre()){
			compteur++;
			std::cout<<std::endl;
			std::cout<<" Entrez la quantite de produit a modifier, avec un - si vous souhaitez supprimez des produits "<<std::endl;
			std::cin>> quantite;
			std::cout<<std::endl;
			(*produit[i]).modifQuantite(quantite);
		}			
	}
	if(compteur==0){
		std::cout<<std::endl;
		std::cout<<" Aucun produit correspondant"<<std::endl;
	}
}

void ajoutClient(Magasin EasyStore){
	std::string nom;
	std::string prenom;
	int id;
	std::vector<Client*> client;
	std::vector<Produit*> panier;
	std::cout<<" Entrez le nom du nouveau client : "<<std::endl;
	std::cin>> nom;
	std::cout<<std::endl;
	std::cout<< " Quel est le prenom du nouveau client : "<<std::endl;
	std::cin>>prenom;
	std::cout<<std::endl;
	client = EasyStore.getClient();
	id = int(client.size() +1);
	Client* ref_client1(0); //declaration d'un pointeur sur un objet
	ref_client1 = new Client (id , nom, prenom, panier);
	EasyStore.ajouterClient(ref_client1);
}


void choixClient(Magasin EasyStore){
	int id;
	std::cout<<" Entrez l'ID d'un client : "<<std::endl;
	std::cin>> id;
	int compteur = 0;
	std::vector<Client*> client;
	client = EasyStore.getClient();
	for(int i = 0; i<int(client.size()); i++){
		if(id == (*client[i]).getId()){
			EasyStore.afficherListeCommandeClient(client[i]);
			compteur++;
		}
	}
		if(compteur == int(client.size())){
			std::cout<< " Aucun client correspondant "<<std::endl;
		}
}

void infoClient(Magasin EasyStore){
	int id;
	std::string nom;
	std::cout<<" Entrez l'ID d'un client : "<<std::endl;
	std::cin>> id;
	std::cout<<" Entrez le nom d'un client : "<<std::endl;
	std::cin>> nom;
	std::cout<<std::endl;
	int compteur =0;
	std::vector<Client*> client;
	client = EasyStore.getClient();
	for(int i = 0; i<int(client.size()); i++){
		if(id == (*client[i]).getId() ||nom == (*client[i]).getNom()){
			compteur++;
			EasyStore.afficherClient(nom, id);
		}
	}
		if(compteur == int(client.size())){
			std::cout<< " Aucun client correspondant "<<std::endl;
		}
}

void livraisonCommande(Magasin EasyStore){
	int id;
	std::cout << " Entrez l'ID de la commande à livrée "<<std::endl;
	std::cin>> id;
	EasyStore.changerStatutCommande(id);
}

void affichageMagasin(Magasin EasyStore){
	int choix;
	system("clear");
	do{
		std::cout<<std::endl;
		std::cout<<" Gestion du magasin "<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 1 - Ajout d’un produit"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 2 - Affichage des produits"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 3 - Mise a jour des quantités"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 4 - Retour au menu principal"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " Entrez votre choix"<< std::endl;
		std::cin >> choix;
		std::cout<<std::endl;

		switch (choix) {
			case 1 :
				ajoutProduit(EasyStore);
				break;
			case 2 :
				EasyStore.afficherListeProduit();
				break;
			case 3 :
				majQuantite(EasyStore);
				break;
			case 4 :
				//retour au menu principal 
				break;
			default :
				std::cout<<std::endl;
				std::cout<<" Votre choix ne correspond à aucune proposition "<<std::endl;
		}
	}
	while(choix != 4 );
}

void affichageClient(Magasin EasyStore){
	system("clear");
	int choix;
	do{
		std::cout<<std::endl;
		std::cout<<" Gestion des clients "<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 1 - Ajout d’un client"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 2 - Affichage des clients"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 3 - Affichage des informations d'un client"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 4 - Retour au menu principal"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " Entrez votre choix"<< std::endl;
		std::cin >> choix;
		std::cout<<std::endl;

		switch (choix) {
			case 1 :
				ajoutClient(EasyStore);
				break;
			case 2 :
				EasyStore.afficherListeClient();
				break;
			case 3 :
				infoClient(EasyStore);
				break;
			case 4 :
				//retour au menu principal 
				break;
			default :
				std::cout<<std::endl;
				std::cout<<" Votre choix ne correspond à aucune proposition "<<std::endl;
		}
	}
	while(choix != 4);
}


void affichageCommande(Magasin EasyStore){
	int choix;
	system("clear");
	do{
		std::cout<<std::endl;
		std::cout<<" Gestion des commandes "<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 1 - Affichage des commandes"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 2 - Affichage des commandes d'un client"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 3 - Changer le statut d'une commande"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 4 - Retour au menu principal"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " Entrez votre choix"<< std::endl;
		std::cin >> choix;
		std::cout<<std::endl;

		switch (choix) {
			case 1 :
				EasyStore.afficherListeCommande();
				break;
			case 2 :
				choixClient(EasyStore);
				break;
			case 3 :
				 livraisonCommande(EasyStore);
				break;
			case 4 :
			//retour au menu principal 
				break;
			default :
				std::cout<<std::endl;
				std::cout<<" Votre choix ne correspond à aucune proposition "<<std::endl;
		}
	}
	while(choix != 4);
}

int affichageMenu(Magasin EasyStore){
	int choix;
	do{
		system("clear");
		std::cout<<std::endl;
		std::cout<<" Menu Principal "<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 1 - Gestion du magasin"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 2 - Gestion des clients"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 3 - Gestion des commandes"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " 4 - Fermer le programme"<<std::endl;
		std::cout<<std::endl;
		std::cout<< " Entrez votre choix"<< std::endl;
		std::cin >> choix;
		std::cout<<std::endl;

		switch (choix) {
			case 1 :
				affichageMagasin(EasyStore);
				break;
			case 2 :
				affichageClient(EasyStore);
				break;
			case 3 :
				affichageCommande(EasyStore);
				break;
			case 4 :
				std::cout<<" Fermeture du programme"<<std::endl;
				return 1;
			default :
				std::cout<<std::endl;
				std::cout<<" Votre choix ne correspond à aucune proposition "<<std::endl;
		}
	}
	while(choix != 4);
}


int main(){

	std::vector<Produit*> liste_produit;
	std::vector<Client*> liste_client;
	std::vector<Commande*> liste_commande;
	std::vector<Produit*> panier;
	std::vector<Produit*> panier2;
	Magasin EasyStore(liste_produit, liste_client, liste_commande);
	
	Client c1(1,"Dupont","Pierre",panier);
	Client *ref_client;
	ref_client = &c1;

	Client c2(2,"Potter","Harry",panier2);
	Client *ref_client2;
	ref_client2 = &c2;

	
	Produit p1("PS5", " Console de jeu de marque Sony", 249.99, 10);
	Produit p2("Xbox", " Console de jeu ", 349.66, 15);
	//Creation d'un pointeur
	Produit *ref_pr1;
	//On affecte la valeur du pointeur au contenu de p1
	ref_pr1 = &p1;

	Produit *ref_pr2;
	ref_pr2 = &p2;

	Produit produit("Jambon","Le jambon c'est bon",8.5,10);
	Produit *ref_produit;
	ref_produit = &produit;

	EasyStore.ajouterProduit(ref_pr1);
	EasyStore.ajouterProduit(ref_pr2);
	EasyStore.ajouterProduit(ref_produit);

	EasyStore.ajouterClient(ref_client);
	EasyStore.ajouterClient(ref_client2);
	
	EasyStore.ajouterProduitClient(ref_client, ref_pr1, 3);
	EasyStore.ajouterProduitClient(ref_client, ref_pr2, 5);
	EasyStore.ajouterProduitClient(ref_client2, ref_produit, 2);
	EasyStore.validerCommande(ref_client);
	EasyStore.validerCommande(ref_client2);

	affichageMenu(EasyStore);
	ecriture_fichier_Produit(EasyStore);
	ecriture_fichier_Client(EasyStore);
	ecriture_fichier_Commande(EasyStore);
	


return 0;	


}