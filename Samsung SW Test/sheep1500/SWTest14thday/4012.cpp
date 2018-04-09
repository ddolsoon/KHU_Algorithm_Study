//
// Created by jameskang on 18. 4. 10.
//
#include <iostream>
#include <math.h>
using namespace std;
#define SIZE 21

int N;
int arr[SIZE][SIZE];
int visit[SIZE];
long long ans=10000000000;

void solve(int index,int count){
    if(index>N+1)
        return;
    if(count==N/2){
        int temp1=0;
        int temp2=0;
        for(int i=1;i<=N;i++){
            if(visit[i]==0){
                for(int j=1;j<=N;j++){
                    if(visit[j]==0){
                        temp1+=arr[i][j];
                    }
                }
            }else if(visit[i]==1){
                for(int j=1;j<=N;j++){
                    if(visit[j]==1){
                        temp2+=arr[i][j];
                    }
                }
            }
        }
        if(ans>abs(temp1-temp2)){
            ans=abs(temp1-temp2);
        }
        return;
    }

    visit[index]=1;
    solve(index+1,count+1);
    visit[index]=0;
    solve(index+1,count);

}
int t,c;
int main(){
    cin>>t;
    while(c++<t){
        ans=10000000000;
        cin>>N;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                cin>>arr[i][j];



        solve(1,0);

        cout<<"#"<<c<<" "<<ans<<endl;
    }
    return 0;
}


