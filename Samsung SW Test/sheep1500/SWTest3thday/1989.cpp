#include <iostream>
#include <string>

using namespace std;

int main() {
    int t,count=0;
    cin>>t;
    while(count++<t){
        string word;
        cin>>word;
        int length = word.length();
        bool check = true;
        for(int i=0;i<length/2;i++){
            if(word[i]!=word[length-1-i])
                check = false;
        }
        cout<<"#"<<count<<" ";
        if(check)
            cout<<1;
        else
            cout<<0;

        cout<<endl;
    }
    return 0;
}