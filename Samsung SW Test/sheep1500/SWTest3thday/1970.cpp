#include <iostream>

using namespace std;

void seperate_money(int start_money,int money){
    if(start_money<10)
        return;
    int f_w =start_money;
    while(f_w>=10){
        f_w/= 10;
    }
    int c = money/ start_money;
    money = money - start_money * c;
    cout<<c<<" ";
    if(f_w==5){
        seperate_money(start_money/5,money);
    }else{
        seperate_money(start_money/2,money);
    }
}

int main() {
    int N,count=0;
    cin>>N;
    while(count++<N){
        int money,start_money = 50000;
        cin>>money;

        cout<<"#"<<count<<endl;
        seperate_money(start_money,money);
        cout<<endl;
    }
    return 0;
}