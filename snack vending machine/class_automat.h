#include<string>
#include<vector>
class Automat{
private:
    std::vector<slot*> slots;
    int  numSlot;
    int numProductsPerSlot;
    coinSlot CoinsSlot;
    keypad keYpad;
    DropCheck DROPChek;
    slot* cached;
public:
    Automat(int numSlots,int numProductsPerSlots){
    numSlot=numSlots;
    numProductsPerSlot=numProductsPerSlots;
    slots.reserve(numSlot);
    //slots = std::vector<slot>(numSlot);
     cached=nullptr;


    }
    ~Automat(){
      for(int i;i<slots.size();i++){
        delete slots[i];
      }
     std::cout<<"Destructor called"<<std::endl;
    }
   bool addslot(std::string prod_name,int id_slott,int price,int motor1){
         Smallslot* a;
         a=new Smallslot(id_slott, prod_name, price,motor1);
          slots.push_back(a);
          return true;
    }
     bool addslot(std::string prod_name,int id_slott,int price,int motor1,int motor2){
         Wideslot* a;
         a=new Wideslot(id_slott, prod_name, price,motor1,motor2);
          //cout<<slots.size();
          slots.push_back(a);
         // cout<<slots.size();
          return true;
    }
    bool addslot(slot*a){
        slots.push_back(a);
         return true;
    }

    slot*  searchSlot(int slotid){

     if(cached!=nullptr && cached->getId()==slotid){

            return cached;

     }
     else{
        for(int i=0;i<slots.size();i++){
            if(slots[i]->getId()==slotid){
                cached=slots[i];
                return cached;
           }
        }
     }
     return nullptr;
}

    void changeSlot(int idSlot,std::string name,int pricee){
         //for(int i=0;i<slots.size();i++){
            slot* searched=searchSlot(idSlot);
                if(searched!=nullptr){
                searched->setProductName(name);
                searched->setPrice(pricee) ;
                cout<<"                                    changes made it succssfully"<<endl;

         }
                 else{
                    cout<<"                                 Slot not fouand!"<<endl;
                 }
         }

    //}


   int getPieces(int id_slot){
       slot* searched=searchSlot(id_slot);
       if(searched!=nullptr){return searched->getNumProducts();}
       else{return -2;}

   }

   int getPrice(int id_slot){
       slot* price_search=searchSlot(id_slot);
       if(price_search!=nullptr){return price_search->getPrice();}
       else{return -2;}
   }
   bool isAviable(int id_slot){

     slot* searched_prod=searchSlot(id_slot);
     if(searched_prod!=nullptr){

        if(getPieces(searched_prod->getId())>0){
            return true;
        }
        else{
            return false;
        }
     }
      else{return false;}
   }

   bool dorpSlot(int id_slot){

      slot* searched=searchSlot(id_slot);
      if(searched!=nullptr){
        if(isAviable(searched->getId())){
            searched->drop();
            searched->setNumProducts(searched->getNumProducts()-1);
            //cout<<"                         Product dropped succsfully!"<<endl;
            return true;
        }
        else{
            //cout<<"                                   Product not fouand!"<<endl;
            return false;
        }
      }

   }
   void fillAll(){

      for(int i=0;i<slots.size();i++){
        slots[i]->setNumProducts(numProductsPerSlot);
      }
   }
   void Fill(int slot_id,int num_pro){

       slot* searched=searchSlot(slot_id);
       if(searched!=nullptr){
        searched->setNumProducts(num_pro);
       }

   }
};

