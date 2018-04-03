//
// Created by jameskang on 18. 4. 3.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define SIZE_N 11

int arr[SIZE_N][SIZE_N];
int visit[SIZE_N][SIZE_N];

int T,N,M,C;
int ans;

int sol[SIZE_N][SIZE_N];

queue<int> q;

// 재귀로 m개의 벌꿀 단지 중 합은 C 이하이면서 제곱은 최대인 경우 구하는 방법!
int func(int m,int x,int y,int sum,int pSum){
    if(m>=M) return pSum;
    int nextSum;
    int max = 0;
    for(int i=m;i<M;++i){
        if(sum+arr[x][y+i]<=C){
            nextSum = func(i+1,x,y,sum+arr[x][y+i],pSum+(arr[x][y+i]*arr[x][y+i]));
            if(max<nextSum)max = nextSum;
        }
        nextSum = func(i+1,x,y,sum,pSum);
        if(max<nextSum)max = nextSum;
    }
    return max;
}

int main(){
    scanf("%d",&T);
    int c = 0;
    while(c++<T){
        int max_i=0;
        int max_j=0;
        int max_value=0;
        memset(arr,0,sizeof(arr));
        memset(visit,0,sizeof(visit));
        scanf("%d %d %d",&N,&M,&C);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&arr[i][j]);
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<=N-M;j++){
                sol[i][j] = func(0,i,j,0,0);
                if(sol[i][j]>max_value){
                    max_value = sol[i][j];
                    max_i = i;
                    max_j = j;
                }

            }
        }

        for(int i=max_j;i<max_j+M;i++){
            visit[max_i][i]=1;
        }
        int second_max=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<=N-M;j++){
                if(visit[i][j]!=1){
                    if(sol[i][j]>second_max){
                        second_max = sol[i][j];
                    }
                }
            }
        }

        printf("#%d %d\n",c,second_max+max_value);
    }


    return 0;
}
