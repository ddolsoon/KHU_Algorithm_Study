#include <iostream>
#include <queue>
#include <vector>

#define MAX 8
using namespace std;


// 필요한 것들!
int array[MAX][MAX];
int memo[MAX][MAX];
int max_value;
vector<pair<int,int>> virus_array;

// 방향키 동서남북
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int m,n;

void copy_array(int (*a)[MAX],int (*b)[MAX]){
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            a[i][j] = b[i][j];
}

int count_max(int (*a)[MAX], int (*b)[MAX]){
    int count = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0) count++;
            a[i][j] = b[i][j];
        }
    }

    return count;
}

void bfs(){
    queue<pair<int,int>> q;
    for(int i=0;i<virus_array.size();i++)
        q.push(virus_array[i]);

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int move_x = x+dx[i];
            int move_y = y+dy[i];
            if(move_x<0 || move_y<0 || move_x>=m || move_y>=n || array[move_x][move_y]!=0) continue;

            array[move_x][move_y]=2;
            q.push(make_pair(move_x,move_y));

        }
    }
}

void dfs(int x,int y,int wall){
    array[x][y] =1;
    memo[x][y]=1;

    if(wall==3){
        int temp_array[MAX][MAX];
        copy_array(temp_array,array);
        bfs();
        max_value = max(max_value,count_max(array,temp_array));

        array[x][y] = 0;
        memo[x][y] = 0;
        return;
    }
    for(int i=x;i<m;i++){
        for(int j=0;j<n;j++){
            if(memo[i][j]==0 && array[i][j]==0){
                dfs(i,j,wall+1);
            }
        }
    }

    array[x][y] = 0;
    memo[x][y] = 0;
}

int main()
{
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&array[i][j]);
            if(array[i][j]==2)
                virus_array.push_back(make_pair(i,j));

        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(array[i][j]==0){
             dfs(i,j,1);
            }
        }
    }

    printf("%d",max_value);
    return 0;
}
