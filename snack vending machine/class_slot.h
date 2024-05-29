#include<string>
class slot{

protected:
    std::string productName;
    int id_slot;
    int numProduct;
    int prix;
    //motor *motor1;
    //motor *motor2;
public:
    //slot(std::string prod_name,int idSlot,int price,int motorId_1,int motorId_2=0){
      /*productName=prod_name;
      id_slot=idSlot;
      numProduct=0;
      prix=price;
      motor1=new motor(motorId_1);
      if(motorId_2==0){motor2=nullptr;}
      else{
         motor2=new motor(motorId_2);
      }


    }
    slot(){};
    ~slot(){
       delete motor1;
       delete motor2;
       std::cout<<"Destructeur called"<<std::endl;

    }
    */
    //slot() {}
    //virtual ~slot() {}
   virtual void drop()=0;
   std::string getProductName (){
      return  productName;
    }
    void setProductName(std::string nom){
       productName=nom;
    }
    int  getNumProducts(){
      return numProduct;

    }
    void setNumProducts(int nombre){
         numProduct=nombre;
    }
    int getPrice(){
      return prix;
    }
    void setPrice(int price){
      prix=price;
    }
    int getId(){
      return id_slot;
    }

};
class Smallslot:public slot{
    motor *motor1;
 public:
     Smallslot(int slotid,std::string prod_name,int price,int motor1_id){
        id_slot=slotid;
        productName=prod_name;
        prix=price;
        numProduct=0;
        motor1=new motor(motor1_id);
     }
     ~Smallslot(){
         delete motor1;
         std::cout<<"Destructor called!"<<std::endl;


     }
     void drop(){
       motor1->trigger();
       std::cout<<productName<<"est livre a parir du logement "<<id_slot<<std::endl;
    }

};
class Wideslot:public slot{

   motor *motor1;
   motor *motor2;

   public:
       Wideslot(int slotid,std::string prod_name,int price,int motor1_id,int motor2_id){
        id_slot=slotid;
        productName=prod_name;
        prix=price;
        numProduct=0;
        motor1=new motor(motor1_id);
        motor2= new motor(motor2_id);

       }
       ~Wideslot(){
         delete motor1;
         delete motor2;
         std::cout<<"Destructor aclled!"<<std::endl;


     }
      void drop(){
       motor1->trigger();
       motor2->trigger();
       std::cout<<productName<<"est livre a parir du logement "<<id_slot<<std::endl;
    }
};
