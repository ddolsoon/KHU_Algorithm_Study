//
// Created by jameskang on 18. 3. 28.
//
#include <iostream>
using namespace std;

#define SIZE 21
#define BACK -1
#define FORWARD 1

int ans;
int arr[SIZE][SIZE];
int memo[SIZE][SIZE];
int length;
int N;
int X;

int check_row(int row){
    length=1;
    for(int i=0;i<N-1;i++){
        if(abs(arr[row][i]-arr[row][i+1])>1)
            return 0;
        else if(arr[row][i+1]-arr[row][i]==1){
            if(length<X)
                return 0;
            if(i-length>=0&&length<2*X&&arr[row][i-length]==arr[row][i+1])
                return 0;
            length=1;
        }else if(arr[row][i+1]-arr[row][i]==-1){
            if(i-length>=0&&arr[row][i-length]>arr[row][i]&&length<X)
                return 0;
            if(i==N-2)
                return 0;
            length=1;
        }else{ //격차가 동일할 때
            length+=1;
            if(i==N-2&&arr[row][i-length]>arr[row][i]&&length<X)
                return 0;
        }
    }
    return 1;
}

int check_col(int col){
    length=1;
    for(int i=0;i<N-1;i++){
        if(abs(arr[i][col]-arr[i+1][col])>1)
            return 0;
        else if(arr[i+1][col]-arr[i][col]==1){
            if(length<X)
                return 0;
            if(i-length>=0&&length<2*X&&arr[i-length][col]==arr[i+1][col])
                return 0;
            length=1;
        }else if(arr[i+1][col]-arr[i][col]==-1){
            if(i-length>=0&&arr[i-length][col]>arr[i][col]&&length<X)
                return 0;
            if(i==N-2)
                return 0;
            length=1;
        }else{ //격차가 동일할 때
            length+=1;
            if(i==N-2&&arr[i-length][col]>arr[i][col]&&length<X)
                return 0;
        }
    }
    return 1;
}
int main(){
    int t;
    int c = 0;
    scanf("%d",&t);
    while(c++<t){
        ans = 0;
        scanf("%d %d",&N,&X);
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&arr[i][j]);

        for(int row=0;row<N;row++){
            ans+=check_row(row);
        }
        for(int col=0;col<N;col++){
            ans+=check_col(col);
        }
        printf("#%d %d\n",c,ans);
    }
    return 0;
}