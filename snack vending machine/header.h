//#include<string>>

#include<iostream>
using namespace std;
class Automat{
private:
    int *slots;
    int  numSlot;
    int numProductsPerSlot;
    int cached;


public:
    Automat(int i,int k){
    numSlot=i;
    numProductsPerSlot=k;
    slots = new int[numSlot];
    for(int j=0;j<numSlot;j++){
        slots[j]=numProductsPerSlot;
    }
    cached=-1;

    }
    ~Automat(){
     delete[] slots;
     cout<<"Destructor called"<<endl;

    }
    void addslot(){
        slots[numSlot]=numProductsPerSlot;
        numSlot++;


    }
    //void affiche(){
      // for(int i=0;i<numSlot;i++){
        //cout<<slots[i]<<endl;
       //}

    //}
    int searchslot(int slot_id){
        if(cached==slot_id){
            return cached;
        }
        else{
            for(int j=0;j<numSlot;j++){
                    if(slots[i]==slot_id){
                        cached=i;
                        return cashed;
                    }

            }
        }

    }

};
/*constructeur : Le paramètre numslots détermine le nombre d'emplacements de produit du machine
a (par exemple, la machine de la figure 3 a 15 emplacements). Créer un tableau dynamique pour les
logements avec suffisamment d’espace mémoire.
Le paramètre numProductsPerSlot détermine le nombre de produits qui peut être stocké dans un
seul emplacement
destructeur: Retourne de la mémoire pour les slots
addSlot() :La méthode devrait ajouter un emplacement de produit à la machine.
searchSlot :Recherche le slotID de slot. La fente doit être retournée comme un retour valeur et
stockée dans l'attribut mis en cache. Chaque recherche devrait d'abord vérifie si l'élément mis en
cache est déjà mis en cache.*/
