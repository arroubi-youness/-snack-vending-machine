using namespace std;
class coinSlot{
private:
    int inseartedAmount;
    float coinValue[7]={200,100,50,20,10,5,1};
public:
    coinSlot(){

      inseartedAmount=0;

    }
    ~coinSlot(){

      cout<<"Destructor called!"<<endl;
    }
int updateCoinAmount(){
    int a;
    cout<<"Please enter the coins:";
    cin>>a;
    if(a==-1){
        cout<<"==> Buying operation has been canceld!"<<endl;
        if(inseartedAmount!=0){cout<<"==>Take your returned money "<<inseartedAmount<<" cent!"<<endl;}
        exit(0);

    }
    else{
        inseartedAmount+=a;
        return  inseartedAmount;
    }

}
int getcoinAmount(){

  return inseartedAmount;
}

void cleaar(){
    inseartedAmount=0;
}


void returnCoins(int price){
int returned_money=inseartedAmount-price;
   // returned_money=returned_money*100;

    if(inseartedAmount==price){
        cout<<"There is no returned coin!"<<endl;
    }
    else if(inseartedAmount<price){
        cout<<"INSEARTED MONEY IS NOT ENOUGH!"<<endl;
    }
    else{cout<<"le montant a rendre est:"<<endl;
    for(int i=0;i<7;i++){

        if(returned_money>=coinValue[i]){
            int k9isma=returned_money/coinValue[i];
            cout<<k9isma<<"x"<<coinValue[i]/100<<"euros"<<endl;
            returned_money=returned_money%(int)coinValue[i];
        }

    }}


 }
};
