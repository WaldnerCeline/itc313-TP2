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

/*
void ecriture_fichier_Produit(){
    std::string const fichier_produit("itc313-TP2/produit.txt");
    std::ofstream monFlux(fichier_produit.c_str());

    if(monFlux){
       //ecriture dans le fichier
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

 


void lecture_fichier_Produit(){
   std::ifstream fichier_produit("itc313-TP2/produit.txt");

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
      std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
   }

}

void ecriture_fichier_Client(){
    std::string const fichier_client("itc313-TP2/client.txt");
    std::ofstream monFlux(fichier_client.c_str());

    if(monFlux){
       //ecriture dans le fichier
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

 


void lecture_fichier_Client(){
   std::ifstream fichier_client("itc313-TP2/client.txt");

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
void ecriture_fichier_Commande(){
    std::string const fichier_commande("itc313-TP2/commande.txt");
    std::ofstream monFlux(fichier_commande.c_str());

    if(monFlux){
       //ecriture dans le fichier
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << estd::ndl;
    }
}

 


void lecture_fichier_Commande(){
   std::ifstream fichier_commande("itc313-TP2/commande.txt");

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
      std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
   }

}*/


void ajoutProduit(Magasin EasyStore){
	std::string titre;
	std::string detail;
	double prix;
	double quantite;
	std::cout<<"Entrez le nom du nouveau produit : "<<std::endl;
	std::cin>> titre;
	std::cout<<std::endl;
	std::cout<< "Quel est le detail de ce produit : "<<std::endl;
	std::cin>>detail;
	std::cout<<std::endl;
	std::cout<<"Entrez le prix unitaire du produit : "<<std::endl;
	std::cin>>prix;
	std::cout<<std::endl;
	std::cout<<"Entrez la quantite a mettre en stock : "<<std::endl;
	std::cin>>quantite;
	std::cout<<std::endl;
	Produit nouveau_produit(titre, detail, prix, quantite);
	Produit *ref_produit;
	ref_produit = &nouveau_produit;
	EasyStore.ajouterProduit(ref_produit);
}



void majQuantite(Magasin EasyStore){
	double quantite;
	std::string nom;
	int choix;
	std::vector<Produit*> produit;
	produit = EasyStore.getClient();
	std::cout<<" Entrez le nom du produit a modifier "<<std::endl;
	cin>> nom;
	for(int i = 0; i<int(produit.size()); i++){
		if((*produit).getTitre() == (*m_produit[i]).getTitre()){
			std::cout<<" Entrez la quantite de produit a modifier "<<std::endl;
			cin>> quantite;
			do{
				std::cout<< "1 - Ajout de produits"<<std::endl;
				std::cout<<std::endl;
				std::cout<< "2 - Suppression de produits"<<std::endl;
				std::cout<<std::endl;
				std::cout<< "Entrez votre choix"<< std::endl;
				std::cin >> choix;

				switch(choix){
					case 1 :
						(*m_produit[i]).modifQuantite(quantite);
						break;
					case 2 :
						(*m_produit[i]).modifQuantite( -quantite);
						break;
					default :
						std::cout<<"Votre choix ne correspond à aucune proposition "<<std::endl;

				}
			}
			while(choix < 1 ||choix >2);			
		}
	}
}


void affichageMagasin(Magasin EasyStore){
	int choix;
	do{
		std::cout<<" Gestion du magasin "<<std::endl;
		std::cout<< "1 - Ajout d’un produit"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "2 - Affichage des produits"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "3 - Mise a jour des quantités"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "4 - Retour au menu principal"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "Entrez votre choix"<< std::endl;
		std::cin >> choix;

		switch (choix) {
			case 1 :
				ajouterProduit(Magasin EasyStore);
				break;
			case 2 :
				EasyStore.afficherListeProduit();
				break;
			case 3 :
				majQuantite(Magasin EasyStore);
				break;
			case 4 :
				affichageMenu();
				break;
			default :
				std::cout<<"Votre choix ne correspond à aucune proposition "<<std::endl;
		}
	}
	while(choix<1 || choix >4 );
}

void affichageClient(Magasin EasyStore){
	int choix;
	do{
		std::cout<<" Gestion des clients "<<std::endl;
		std::cout<< "1 - Ajout d’un client"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "2 - Affichage des clients"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "3 - Retour au menu principal"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "Entrez votre choix"<< std::endl;
		std::cin >> choix;

		switch (choix) {
			case 1 :
				
				break;
			case 2 :
				EasyStore.afficherListeClient();
				break;
			case 3 :
				affichageMenu(Magasin EasyStore);
				break;
			default :
				std::cout<<"Votre choix ne correspond à aucune proposition "<<std::endl;
		}
	}
	while(choix<1 || choix > 3);
}


void affichageCommande(Magasin EasyStore){
	int choix;
	do{
		std::cout<<" Gestion des commandes "<<std::endl;
		std::cout<< "1 - Affichage des commandes"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "2 - Changer le statut d'une commande"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "3 - Supprimer une commande"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "4 - Retour au menu principal"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "Entrez votre choix"<< std::endl;
		std::cin >> choix;

		switch (choix) {
			case 1 :
				
				break;
			case 2 :
				
				break;
			case 3 :
				 
				break;
			case 4 :
				affichageMenu(Magasin EasyStore);
				break;
			default :
				std::cout<<"Votre choix ne correspond à aucune proposition "<<std::endl;
		}
	}
	while(choix < 1 || choix >4);
}

void affichageMenu(Magasin EasyStore){
	int choix;
	do{
		std::cout<<" Menu Principal "<<std::endl;
		std::cout<< "1 - Gestion du magasin"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "2 - Gestion des clients"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "3 - Gestion des commandes"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "4 - Fermer le programme"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "Entrez votre choix"<< std::endl;
		std::cin >> choix;

		switch (choix) {
			case 1 :
				affichageMagasin(Magasin EasyStore);
				break;
			case 2 :
				affichageClient(Magasin EasyStore);
				break;
			case 3 :
				affichageCommande(Magasin EasyStore);
				break;
			case 4 :
				std::cout<<"Fermeure du programme"<<std::endl;
				return 0;
			default :
				std::cout<<"Votre choix ne correspond à aucune proposition "<<std::endl;
		}
	}
	while(choix<1 || choix > 4);
}



int main(){
	std::vector<Produit*> liste_produit;
	std::vector<Client*> liste_client;
	std::vector<Commande*> liste_commande;
	Magasin EasyStore(liste_produit, liste_client, liste_commande);
	affichageMenu(EasyStore);
	Client c1(1,"Dupont","Pierre",panier);
	Client *ref_client;
	ref_client = &c1;
	Produit p1("Jambon","Le jambon c'est bon",8.5,10);
	Produit *ref_produit;
	ref_produit = &p1;
	EasyStore.ajouterProduit(ref_produit);
	EasyStore.afficherListeProduit();
	EasyStore.ajouterClient(ref_client);
	EasyStore.afficherListeClient();
	EasyStore.ajouterProduitClient(ref_client, ref_produit, 3);

return 0;	


}