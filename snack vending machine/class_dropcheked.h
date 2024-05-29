#include <cstdlib> // Pour rand() et srand()
#include <ctime>

class DropCheck{

    int possibilty;
public:
    DropCheck(){
       possibilty=0;

    }
    ~DropCheck(){}
    bool productRealeased(){
       srand(time(NULL));
       possibilty=rand()%100;
       if(possibilty<=10){
        return false;
       }
       else{
        return true;
       }



    }

};
