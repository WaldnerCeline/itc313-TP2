#include "magasin.h"
#include <vector>

int main(){

int *p1 = new std::vector<Product*> produit;
int *p2 = new std::vector<Client*> client;
int *p3 = new std::vector<Commande*> commande;

Magasin EasyStore(produit,client,commande);

delete [] p1;
delete [] p2;
delete [] p3;

return 0;
}
