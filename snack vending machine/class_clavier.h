
class keypad{
private:
    int selected_emplacement;
public:
    keypad(){

    selected_emplacement=0;
    }
   ~keypad(){};

    int getSelection(){
        int selected;
       cout<<"Select a product by entering its number:";
       cin>>selected;
       if(selected==-1){
        cout<<"buying operation canceled!"<<endl;
        exit(0);
       }
       else{
        selected_emplacement=selected;
        return selected_emplacement;
       }




   }


};
