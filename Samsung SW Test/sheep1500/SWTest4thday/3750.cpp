//
// Created by jameskang on 18. 3. 19.
//
#include <iostream>
#include <string>
using namespace std;

int main(){

    int t;
    int c = 0;
    cin>>t;
    while(c++<t){
        string f;
        cin>>f;
        while(f.length()!=1){
            int temp=0;
            for(int i=0;i<f.length();i++){
                string t;
                t += f[i];
                temp += atoi(t.c_str());
            }
            f = to_string(temp);
        }
        cout<<"#"<<c<<" "<<f<<endl;
    }
    return 0;
}

