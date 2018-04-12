//
// Created by jameskang on 18. 4. 11.
//
#include <iostream>
#include <algorithm>
#include <queue>
#define SIZE 14


using namespace std;

int ans;
int D,W,K;
int map[SIZE][SIZE];

bool checkD(){
    int length;
    bool check;
    for(int y=0;y<W;y++){
        check = false;
        length=1;
        for(int x=1;x<D;x++){
            if(map[x][y]!=map[x-1][y]){
                length=1;
            } else{
                length++;
            }
            if(length>=K){
                check = true;
                break;
            }
        }
        if(!check){
            return false;
        }
    }
    return true;
}
void solve(int current,int count, int array[SIZE]){
    if(ans<=count)
        return;
    if(current>=D)
        return;

    int map2[SIZE][SIZE];

    for(int i=0;i<D;i++)
        for(int j=0;j<W;j++)
            map2[i][j] = map[i][j];

    for(int x=0;x<=current;x++){
        if(array[x]==2)
            continue;
        for(int y=0;y<W;y++){
            map2[x][y] = array[x];
        }
    }

    int length;
    bool check;
    bool check_final = true;
    for(int y=0;y<W;y++){
        check = false;
        length=1;
        for(int x=1;x<D;x++){
            if(map2[x][y]!=map2[x-1][y])
                length=1;
            else
                length++;


            if(length>=K){
                check = true;
                break;
            }
        }
        if(!check){
            check_final=false;
            break;
        }
    }
    if(check_final) {
        ans = min(ans,count);
    }else{
        if(current<D){
            array[current+1] = 2;
            solve(current+1,count,array);
            array[current+1] = 0;
            solve(current+1,count+1,array);
            array[current+1] = 1;
            solve(current+1,count+1,array);
        }
    }
}
//queue<mapcnt> q;
//void bfs(){
//    int map2[SIZE][SIZE];
//    mapcnt t;
//    t.arr[0] = 0;
//    t.current = 0;
//    q.push(t);
//    t.arr[0] = 1;
//    t.current = 0;
//    q.push(t);
//    t.arr[0] = 2;
//    t.current = 0;
//    q.push(t);
//
//    while(!q.empty()){
//        int result = 0;
//        for(int i=0;i<D;i++)
//            for(int j=0;j<W;j++)
//                map2[i][j] = map[i][j];
//
//        mapcnt tmp = q.front();
//        q.pop();
//
//        for(int i=0;i<D;i++){
//            if(!tmp.arr[i])
//                continue;
//
//            for(int j=0;j<W;j++){
//                map2[i][j] = tmp.arr[i]-1;
//            }
//            result++;
//        }
//        int length;
//        bool check;
//        bool check_final = true;
//        for(int y=0;y<W;y++){
//            check = false;
//            length=1;
//            for(int x=1;x<D;x++){
//                if(map2[x][y]!=map2[x-1][y]){
//                    length=1;
//                } else{
//                    length++;
//                }
//
//                if(length>=K){
//                    check = true;
//                    break;
//                }
//            }
//            if(!check){
//                check_final=false;
//                break;
//            }
//        }
//        if(check_final){
//            ans = min(ans,result);
//        }else{
//            if(tmp.current<D-1){
//                int nextCur = tmp.current+1;
//                tmp.current = nextCur;
//                tmp.arr[nextCur] = 0;
//                q.push(tmp);
//                tmp.arr[nextCur] = 1;
//                q.push(tmp);
//                tmp.arr[nextCur] = 2;
//                q.push(tmp);
//            }
//        }
//
//    }
//}

int main(){
    int t;
    int c =0;
    scanf("%d",&t);
    while(c++<t){
        // 이쯤 되면 최대임 D<=13 이니깐
        ans = 10000000;
        scanf("%d %d %d",&D,&W,&K);
        for(int i=0;i<D;i++){
            for(int j=0;j<W;j++){
                scanf("%d",&map[i][j]);
            }
        }
        if(checkD()){
            ans = 0;
        }else{
            int array[SIZE];
            array[0] = 2;
            solve(0,0,array);
            array[0] = 0;
            solve(0,1,array);
            array[0] = 1;
            solve(0,1,array);
        }
        printf("#%d %d\n",c,ans);
    }
    return 0;
}
