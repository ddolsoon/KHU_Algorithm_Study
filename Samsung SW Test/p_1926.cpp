#include <iostream>
#include <cmath>
using namespace std;

int check3(int n){
    if(n<1){
        return 0;
    }
    int temp = n;
    int count = 0;
    while(temp>=10){
        temp = temp/10;
        count+=1;
    }
    int check = 0;
    if(temp%3==0){
        check = 1;
    }else{
        check = 0;
    }
    return check + check3(n);

}

int main(){
    int n;
    cin>>n;

    if(n>=10 && n<=1000){
        for(int i=1;i<=n;i++){
            cout<<check3(i)<<" ";
        }
    }
}

