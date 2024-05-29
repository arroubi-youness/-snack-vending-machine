#include <iostream>
#include <iomanip>
#include"class_motor.h"
#include"class_slot.h"
#include"coinSlot.h"
#include"class_clavier.h"
#include"class_dropcheked.h"
#include "class_automat.h"
using namespace std;



void affiche_head(){
for(int i=0;i<84;i++){
if(i<23){
cout<<" ";
}
else
cout<<"+";
}

cout<<endl;
cout<<"                           Enjoy your day by eating or drinking some thing yummy!"<<endl;
for(int j=0;j<84;j++){
if(j<23){
cout<<" ";
}
else
cout<<"+";
}
cout<<"\n";
}




int main()
{
Automat a(9,12);
a.addslot("1-Mrindina",1,600,1);
a.addslot("2-Dybala",2,550,2,3);
a.addslot("3-MilwiMe",3,770,4,5);
a.addslot("4-TwiMan",4,680,6);
a.addslot("5-TOnikPE",5,710,7);
a.addslot("6-MatinAK",6,700,8);
a.addslot("7-Coffe",7,910,9);
a.addslot("8-TeaMunth",8,870,10);
a.addslot("9-MilkCake",9,740,11);
int choose=0;
int pass=0;
affiche_head();
cout<<endl;
do{
cout<<"                            Choose 1 if you are an admin or 2 if you wanna buy:";
cin>>choose;
if(choose==1){
cout<<endl;
cout<<"                                        Enter the password:";
cin>>pass;
if(pass==1234){
int l;
cout<<endl;
do{
cout<<"                                                Tasks:"<<endl;
cout<<"                                              1-Add slot"<<endl;
cout<<"                                              2-Change slot"<<endl;
cout<<"                                              3-Fill slot"<<endl;
cout<<endl;
cout<<"                                            Choose Number:";
cin>>l;
}while(l>3 || l<1);
switch(l){

case 1:
  {


   std::string nom;
   int id;
   int price;
   int moto1;
   int moto2;
   int nbr_produ;
   cout<<endl;
   cout<<"                                      Enter the number of products:";
   cin>>nbr_produ;
   cout<<endl;
   for(int i=0;i<nbr_produ;i++){
   cout<<"                                         Enter the name:";
   cin>>nom;
   cout<<"                                          Enter the id:";
   cin>>id;
   cout<<"                                          Enter price: ";

   cin>>price;
   cout<<"                                          Enter id motor 1: ";
   cin>>moto2;
   if(id==1||id==2||id==3){
    cout<<"                                          Enter  motor 2:";
    cin>>moto2;
    a.addslot(nom,id,price,moto1,moto2);
   }
   a.addslot(nom,id,price,moto1);
   }
    break;
}
case 2:
  {


   std::string newnom;
   int newid;
   int newprice;
   cout<<endl;
   cout<<"                               Enter the id of the element that you wanna chaange:";
   cin>>newid;
   cout<<"                                             Enter the new name:";
   cin>>newnom;
   cout<<"                                             Enter new price: ";
   cin>>newprice;
   a.changeSlot(newid,newnom,newprice);
   break;
   }
case 3:
  {


  int i=0;
cout<<"                                  Enter the id that you wanna fill:";
cin>>i;
if(!a.isAviable(i)){
    a.Fill(i,6);
}
else{
    cout<<"                              The slot is not empty!"<<endl;
}


break;
}

}

}

}

else if(choose==2){
cout<<endl;
cout<<endl;
for(int i=0;i<120;i++){
cout<<"*";
}
//cout<<endl;
cout<<"                                                         Products"<<endl;

for(int i=0;i<120;i++){
cout<<"*";
}
for(int i=0;i<9;i=i+3){
cout<<"||"<<std::setw(13)<<" "<<std::setw(11)<<a.searchSlot(i+1)->getProductName()<<std::setw(13)<<" "<<"||"<<std::setw(13)<<" "<<std::setw(11)<<a.searchSlot(i+2)->getProductName()<<std::setw(13)<<" "<<"||"
<<std::setw(13)<<" "<<std::setw(11)<<a.searchSlot(i+3)->getProductName()<<std::setw(14)<<" "<<"||"<<endl;
for(int i=0;i<120;i++){
cout<<"*";
}
cout<<endl;
}

//choosing product and entring coin!!!!!
keypad b;
coinSlot c;
DropCheck e;
int s=0;
bool pourcentage;
int id_selected;
do{
    id_selected=b.getSelection();
}while(id_selected<1||id_selected>9);

cout<<"The price of the product is: "<<a.searchSlot(id_selected)->getPrice()<<" cents!"<<endl;


do{
s=c.updateCoinAmount();

}while(a.getPrice(id_selected)>s);
///returened mony
while(!pourcentage){
pourcentage=e.productRealeased();



}
a.searchSlot(id_selected)->drop();
c.returnCoins(a.getPrice(id_selected));
c.cleaar();

for(int i=0;i<4;i++){
cout<<endl;
}

}


else{
cout<<"                                     You had chose a wrong number !"<<endl;
}




}while(choose<1||choose>2);
return 0;
}
