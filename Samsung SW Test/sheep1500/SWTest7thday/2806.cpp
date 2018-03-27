#include <iostream>
#include <cstring>
#include<algorithm>

#define SIZE 10

using namespace std;

int ans;
int N;
int arr[SIZE];

bool isPromising(int index){
    for(int i=0;i<index;i++){
        if(arr[i]==arr[index]) return false;
        if((arr[i]-arr[index])==index-i) return false;
        if((arr[index]-arr[i])==index-i) return false;
    }
    return true;
}

void dfs(int size){
    if(size==N){
        ans++;
    }else{
        for(int i=0;i<N;i++){
            arr[size]=i;
            if(isPromising(size))
                dfs(size+1);
        }
    }

}

int main() {
    int t;
    int c=0;
    scanf("%d",&t);

    while(c++<t){
        ans =0;
        scanf("%d",&N);
        memset(arr,0,sizeof(arr));

        dfs(0);

        printf("#%d %d\n",c,ans);
    }
    return 0;
}