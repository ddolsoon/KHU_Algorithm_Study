#include <iostream>
#include <cstring>
#include <vector>
#include<algorithm>

#define SIZE 101

using namespace std;

int arr[SIZE][SIZE];
int memo[SIZE][SIZE];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int M,N;
int min_value=10000;

vector<pair<int,int>> v;
bool check = true;

void bfs(){
    
}


int main() {
    memset(arr,0,sizeof(arr));
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++) {
            scanf("%1d",&arr[i][j]);
        }
    }
    bfs();
    printf("%d\n",min_value);
    return 0;
}

