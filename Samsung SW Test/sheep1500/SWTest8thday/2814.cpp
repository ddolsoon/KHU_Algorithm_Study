#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;
#define SIZE 11

int N,M;
int arr[SIZE][SIZE];
int memo[SIZE];


int longestLength;



void dfs(int depth,int pos){
    if(depth>longestLength){
        longestLength = depth;
    }

    memo[pos] = 1;
    for(int i=1;i<=N;i++){
        if(pos!=i&&arr[pos][i]&&!memo[i]){
            dfs(depth+1,i);
            memo[i] = 0;
        }
    }
}


int main(){
    int t,c;
    c = 0;
    scanf("%d",&t);
    while(c++<t){
        memset(arr,0,sizeof(arr));
        memset(memo,0,sizeof(memo));
        scanf("%d %d",&N,&M);
        for(int i=0;i<M;i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            arr[x][y] = 1;
            arr[y][x] = 1;
        }

        if(!M){
            longestLength=1;
        }
        else{
            for(int i=1;i<=N;i++){
                memset(memo,0,sizeof(memo));
                dfs(1,i);
            }
        }

        printf("#%d %d\n",c,longestLength);
        longestLength=0;
    }
    return 0;
}
