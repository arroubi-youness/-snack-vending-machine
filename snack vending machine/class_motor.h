class motor{
 private:
     int id;
 public:
     motor(int id_motor){
     id=id_motor;
     }
    void trigger(){
      std::cout<<"le motor de l'id "<<id<<" est activee"<<std::endl;
    }

};
