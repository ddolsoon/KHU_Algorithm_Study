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
    if(m>=M)
        return pSum;
    int nextSum;
    int max = 0;
    for(int i=m;i<M;i++){
        if(sum+arr[x][y+i]<=C){
            nextSum = func(i+1,x,y,sum+arr[x][y+i],pSum+(arr[x][y+i]*arr[x][y+i]));
            if(nextSum>max)
                max = nextSum;
        }
        nextSum = func(i+1,x,y,sum,pSum);
        if(nextSum>max)
            max = nextSum;
    }
    return max;
}
int checkRow(int x,int y){
    int result=0;
    for(int i=0;i<y-M;i++){
        if(result<sol[x][i]) result = sol[x][i];
    }
    for(int i=y+M;i<=N-M;i++){
        if(result<sol[x][i]) result = sol[x][i];
    }
    return result;
}
int checkCol(int x){
    int result = 0;
    for(int i=0;i<N;i++){
        if(i==x)
            continue;
        for(int j=0;j<=N-M;j++){
            if(result<sol[i][j])
                result = sol[i][j];
        }
    }
    return result;
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
        // 이렇게 하면 문제가 생길 수 있다! 두번째 큰 값이 첫번째의 같은 가로행의 왼쪽에 있을 경우 문제가 생김!
//        for(int i=0;i<N;i++){
//            for(int j=0;j<=N-M;j++){
//                if(visit[i][j]!=1){
//                    if(sol[i][j]>second_max){
//                        second_max = sol[i][j];
//                    }
//                }
//            }
//        }
//        for(int i=0;i<N;i++){
//            for(int j=0;j<=N-M;j++){
//                // 이런식으로 매번 3개씩 검사하면 너무 많으니 max_i 행을 아니 그거 제외랑 그거 뺴고 함
//                for(int k=j;k<j+M;j++){
//                    if(visit[i][k]==1) {
//                    }
//                }
//                if(visit[i][j]!=1){
//                    if(sol[i][j]>second_max){
//                        second_max = sol[i][j];
//                    }
//                }
//            }
//        }
        second_max = max(checkRow(max_i,max_j),checkCol(max_i));

        printf("#%d %d\n",c,second_max+max_value);
    }


    return 0;
}
