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
/*constructeur : Le param�tre numslots d�termine le nombre d'emplacements de produit du machine
a (par exemple, la machine de la figure 3 a 15 emplacements). Cr�er un tableau dynamique pour les
logements avec suffisamment d�espace m�moire.
Le param�tre numProductsPerSlot d�termine le nombre de produits qui peut �tre stock� dans un
seul emplacement
destructeur: Retourne de la m�moire pour les slots
addSlot() :La m�thode devrait ajouter un emplacement de produit � la machine.
searchSlot :Recherche le slotID de slot. La fente doit �tre retourn�e comme un retour valeur et
stock�e dans l'attribut mis en cache. Chaque recherche devrait d'abord v�rifie si l'�l�ment mis en
cache est d�j� mis en cache.*/
