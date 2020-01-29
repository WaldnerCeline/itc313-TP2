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


void affichageMagasin(Magasin EasyStore){
	int choix;
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
				
				break;
			case 3 :
				 
				break;
			case 4 :
				affichageMenu();
				break;
			default :
				std::cout<<"Votre choix ne correspond à aucune proposition "<<std::endl;
		}
}

void affichageClient(Magasin EasyStore){
	int choix;
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

void affichageCommande(Magasin EasyStore){
	int choix;
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

void affichageMenu(Magasin EasyStore){
	int choix;
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



int main(){
	std::vector<Produit*> liste_produit;
	std::vector<Client*> liste_client;
	std::vector<Commande*> liste_commande;
	Magasin EasyStore(liste_produit, liste_client, liste_commande);
	affichageMenu(EasyStore);

	delete [] ref_produit;
return 0;	


}