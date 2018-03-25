//
// Created by jameskang on 18. 3. 19.
//
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string array[1000];

int main(){

    int t;
    int c = 0;
    cin>>t;
    while(c++<t){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>array[i];

        cout<<"#"<<c<<" ";
        int half = ceil(n/2.0);
        for(int i=0;i<half;i++){
            cout<<array[i]<<" ";
            if(half+i<n){
                cout<<array[i+half]<<" ";
            }
        }

        cout<<endl;
    }
    return 0;
}
