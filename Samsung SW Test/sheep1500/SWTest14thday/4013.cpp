//
// Created by jameskang on 18. 3. 28.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define SIZE 20
using namespace std;

int ans,K;
int arr[4][8];
int arrK[SIZE];
vector<pair<int,int>> v;



void moveTopni(int pos,int way){
    int temp;
    if(way==1){
        temp = arr[pos][7];
        for(int i=6;i>=0;i--){
            arr[pos][i+1] = arr[pos][i];
        }
        arr[pos][0] = temp;
    }else{
        temp = arr[pos][0];
        for(int i=1;i<8;i++){
            arr[pos][i-1] = arr[pos][i];
        }
        arr[pos][7] = temp;
    }
}

int score(){
    int result=0;
    for(int i=0;i<4;i++){
        if(arr[i][0]==1){
            result+=pow(2,i);
        }
    }

    return result;

}
void changeTopni(int pos, int way){
    int left = pos;
    int right = pos;
    while(left>0){
        if(arr[left][6]==arr[left-1][2])
            break;
        left--;
    }

    while(right<3){
        if(arr[right][2]==arr[right+1][6])
            break;
        right++;
    }
    int left_way = way;
    int right_way = way;
    moveTopni(pos,way);
    for(int i=pos-1;i>=left;i--){
        left_way*=-1;
        moveTopni(i,left_way);
    }
    for(int i=pos+1;i<=right;i++){
        right_way*=-1;
        moveTopni(i,right_way);
    }
}
int main(){
    int t;
    int c = 0;
    scanf("%d",&t);
    while(c++<t){
        v.clear();
        ans=0;
        scanf("%d",&K);
        for(int i=0;i<4;i++)
            for(int j=0;j<8;j++)
                scanf("%d",&arr[i][j]);

        for(int i=0;i<K;i++){
            int pos,way;
            scanf("%d %d",&pos,&way);
            pos-=1;
            v.push_back(make_pair(pos,way));
        }
        for(int i=0;i<v.size();i++){
            int pos =v[i].first;
            int direction =v[i].second;
            changeTopni(pos,direction);
        }
        ans = score();
        printf("#%d %d\n",c,ans);
    }
    return 0;
}
