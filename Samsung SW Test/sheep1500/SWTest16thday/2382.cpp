//
// Created by jameskang on 18. 4. 14.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define SIZE_N 101
#define SIZE_K 1001
#define SIZE_M 1001


using namespace std;
struct Node{
    int x;
    int y;
    bool live_check;
    int direction;
    int num_misang;
};

//struct Misaeng{
//    vector<Node> v;
//    int num;
//};
// 이동방향 상 1, 하 2, 좌 3,우 4
long long ans;
int N,K,M;
//Misaeng arr_N[SIZE_N][SIZE_N];
Node arr_K[SIZE_K];
vector<int> v;
void solve(){
        for(int i=0;i<K;i++){
            if(arr_K[i].live_check){
                // 상
                if(arr_K[i].direction==1) {
                    arr_K[i].x--;
                    if(arr_K[i].x==0){
                        arr_K[i].num_misang/=2;
                        if(arr_K[i].num_misang==0)
                            arr_K[i].live_check=false;
                        else
                            arr_K[i].direction = 2;
                    }
                }// 하
                else if(arr_K[i].direction==2){
                    arr_K[i].x++;
                    if(arr_K[i].x==N-1){
                        arr_K[i].num_misang/=2;
                        if(arr_K[i].num_misang==0)
                            arr_K[i].live_check=false;
                        else
                            arr_K[i].direction = 1;
                    }
                }// 좌
                else if(arr_K[i].direction==3){
                    arr_K[i].y--;
                    if(arr_K[i].y==0){
                        arr_K[i].num_misang/=2;
                        if(arr_K[i].num_misang==0)
                            arr_K[i].live_check=false;
                        else
                            arr_K[i].direction = 4;
                    }
                }// 우
                else if(arr_K[i].direction==4){
                    arr_K[i].y++;
                    if(arr_K[i].y==N-1){
                        if(arr_K[i].num_misang==0)
                            arr_K[i].live_check=false;
                        else
                            arr_K[i].direction = 3;
                    }
                }
            }
        }
        for(int i=0;i<K;i++){
            if(arr_K[i].live_check){
                v.clear();
                v.push_back(i);
                for(int j=i+1;j<K;j++){
                    if(arr_K[j].live_check&&arr_K[i].x==arr_K[j].x&&arr_K[i].y==arr_K[j].y){
                        v.push_back(j);
                    }
                }
                int max_index=0;
                int max_misang = 0;
                for(int index=0;index<v.size();index++){
                    if(arr_K[v[index]].num_misang>max_misang){
                        max_misang=arr_K[v[index]].num_misang;
                        max_index =v[index];
                    }
                }

                for(int index=0;index<v.size();index++){
                    if(v[index]!=max_index){
                        arr_K[max_index].num_misang+=arr_K[v[index]].num_misang;
                        arr_K[v[index]].live_check = false;
                    }
                }
                printf("최고 index%d x:%d y:%d 미생물:%d 방향:%d\n",max_index,arr_K[max_index].x,arr_K[max_index].y,arr_K[max_index].num_misang,arr_K[max_index].direction);
            }
        }
    printf("마무리\n");
    for(int i=0;i<K;i++){
        if(arr_K[i].live_check)
            printf("최고 index%d x:%d y:%d 미생물:%d 방향:%d\n",i,arr_K[i].x,arr_K[i].y,arr_K[i].num_misang,arr_K[i].direction);
    }
    printf("다음=============\n");
}

int main(){
    int t,c=0;
    scanf("%d",&t);
    while(c++<t){
        ans=0;
        scanf("%d %d %d",&N,&M,&K);
        printf("%d번째----------------------------------------------------\n",c);
        for(int i=0;i<K;i++){
            Node node;
            scanf("%d %d %d %d",&node.x,&node.y,&node.num_misang,&node.direction);
            node.live_check=true;
            arr_K[i] = node;
        }


        for(int i=0;i<M;i++)
            solve();

        for(int i=0;i<K;i++)
            if(arr_K[i].live_check)
                ans+=arr_K[i].num_misang;

        printf("#%d %d\n",c,ans);
    }

    return 0;
}


