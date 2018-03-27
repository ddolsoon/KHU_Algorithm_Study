#include <iostream>
#include <cstring>
#include<algorithm>

#define SIZE 10

using namespace std;

int ans;
int N;
int arr[SIZE][SIZE];

bool check_col[15];
bool check_dig[40];
bool check_dig2[40];

bool check(int row,int col){

    if(check_col[col])
        return false;
    if(check_dig[row+col])
        return false;
    if(check_dig2[row-col+N])
        return false;

    return true;
}

int calc(int row){
    if(row==N){
        return 1;
    }
    int cnt = 0;
    for(int col = 0;col<N;col++){
        if(check(row,col)){
            check_dig[row+col] = true;
            check_dig2[row-col+N] = true;
            check_col[col] = true;
            arr[row][col] = true;
            cnt+=calc(row+1);
            check_dig[row+col] = false;
            check_dig2[row-col+N] = false;
            check_col[col] = false;
            arr[row][col] = false;
        }
    }
    return cnt;
}

int main() {
    int t;
    int c=0;
    scanf("%d",&t);

    while(c++<t){
        ans =0;
        scanf("%d",&N);
        memset(arr,0,sizeof(arr));

        ans = calc(0);

        printf("#%d %d\n",c,ans);
    }
    return 0;
}