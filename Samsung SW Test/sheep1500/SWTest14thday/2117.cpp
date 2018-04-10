//
// Created by jameskang on 18. 4. 10.
//
#include <iostream>
#include <algorithm>

using namespace std;
#define SIZE 21
int arr[SIZE][SIZE];
int k_arr[SIZE];
int ans;
int N,M;

int checkDiamond(int x,int y,int k){
    int temp_x = x;
    int temp_y = y;
    int result= 0;

    if(arr[temp_x][temp_y]==1)
        result++;
    // x의 위로 비교
    for(int dx=temp_x-1;dx>=temp_x-k+1&&dx>0;dx--)
        if(arr[dx][temp_y]==1)
            result++;
    // x의 아래로 비교
    for(int dx=temp_x+1;dx<=temp_x+k-1&&dx<=N;dx++)
        if(arr[dx][temp_y]==1)
            result++;


    for(int i=1;i<k;i++){
        int left_temp_y = temp_y-i;
        int right_temp_y = temp_y+i;
        int temp_k = k-i;
        if(left_temp_y>0){
            // 해당 인덱스에 들어가는 값
            if(arr[temp_x][left_temp_y]==1)
                result++;
            // x의 위로 비교
            for(int dx=temp_x-1;dx>=temp_x-temp_k+1&&dx>0;dx--)
                if(arr[dx][left_temp_y]==1)
                    result++;
            // x의 아래로 비교
            for(int dx=temp_x+1;dx<=temp_x+temp_k-1&&dx<=N;dx++)
                if(arr[dx][left_temp_y]==1)
                    result++;
        }

        if(right_temp_y<=N){
            // 해당 인덱스에 들어가는 값
            if(arr[temp_x][right_temp_y]==1)
                result++;
            // x의 위로 비교
            for(int dx=temp_x-1;dx>=temp_x-temp_k+1&&dx>0;dx--)
                if(arr[dx][right_temp_y]==1)
                    result++;
            // x의 아래로 비교
            for(int dx=temp_x+1;dx<=temp_x+temp_k-1&&dx<=N;dx++)
                if(arr[dx][right_temp_y]==1)
                    result++;
        }
    }
    int result_gop = result*M;
    int gop = k*k+(k-1)*(k-1);
    if(gop<=result_gop){
        return result;
    }
    return 0;
}

void solve(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N+1;k++){
                ans = max(ans,checkDiamond(i,j,k));
            }
        }
    }
}


int main(){
    for(int i=1;i<=20;i++){
        k_arr[i] = i*i + (i-1)*(i-1);
    }
    int t;
    int c=0;
    scanf("%d",&t);
    while(c++<t){
        ans=0;
        scanf("%d %d",&N,&M);
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                scanf("%d",&arr[i][j]);

        solve();
        printf("#%d %d\n",c,ans);
    }
    return 0;
}

