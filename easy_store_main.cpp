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



void affichageMagasin(){
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

void affichageClient(){
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
				affichageMenu();
				break;
			default :
				std::cout<<"Votre choix ne correspond à aucune proposition "<<std::endl;
		}
}

void affichageCommande(){
	int choix;
		std::cout<<" Gestion des commandes "<<std::endl;
		std::cout<< "1 - Ajout d’un produit"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "2 - Affichage des commandes"<<std::endl;
		std::cout<<std::endl;
		std::cout<< "3 - Mise a jour des quantitéss"<<std::endl;
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
				affichageMenu();
				break;
			default :
				std::cout<<"Votre choix ne correspond à aucune proposition "<<std::endl;
		}
}

void affichageMenu(){
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
				affichageMagasin();
				break;
			case 2 :
				affichageClient();
				break;
			case 3 :
				affichageCommande();
				break;
			case 4 :
				std::cout<<"Fermeure du programme"<<std::endl;
				return 0;
			default :
				std::cout<<"Votre choix ne correspond à aucune proposition "<<std::endl;
		}
}



int main(){
	


}