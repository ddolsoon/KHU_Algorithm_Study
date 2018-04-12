//
// Created by jameskang on 18. 3. 29.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define SIZE 10
#define SIZE_K 1001
using namespace std;

struct Node{
    int num;
    int time;
    int a_num;
    int b_num;
};

struct Desk{
    bool exist;
    int time;
    int spare_time;
    int num;
};
Node ki[SIZE_K];
int N,M,K;
Desk ai[SIZE];
Desk bi[SIZE];
int A,B;
int ans;

void solve(){
    int time =0;
    int befor_index=1;
    queue<int> before_q;
    queue<int> after_q;
    bool check_middle = false;
    while(1){
//        printf("time : %d\n",time);
        // 처음에 도착했을 때 시간 비교해서 before_q 에 넣어준다!
        for(befor_index;befor_index<=K;befor_index++){
            if(time==ki[befor_index].time){
                before_q.push(ki[befor_index].num);
//                printf("before에 들어감 : %d가 ㅅ간 : %d\n",befor_index,ki[befor_index].time);
            }else{
                break;
            }
        }
        // N창고 단계 1, 고객 넣어주기전에 시간빼고 고객 빼서 중간에 넣기
        for(int i=1;i<=N;i++){
            if(ai[i].exist==true){
                ai[i].spare_time--;
//                printf("ai[%d]가 true일 때 남은 시간 : %d\n",i,ai[i].spare_time);
                if(ai[i].spare_time==0){
                    ai[i].exist = false;
                    after_q.push(ai[i].num);
                    check_middle=true;
//                    check_middle = true;
                }
            }
        }

        // N창고 단계2, 처음 기다리는 고객 N창구에 넣어준다!
        if(!before_q.empty()){
            int a_index = before_q.front();
            for(int i=1;i<=N;i++){
                if(ai[i].exist!=true){
//                    printf("ai[%d]가 비어있을 때 들어가는 것들 : %d",i,a_index);
                    ai[i].exist=true;
                    ai[i].spare_time=ai[i].time;
                    ai[i].num = a_index;
                    ki[a_index].a_num = i;
                    before_q.pop();
                    if(before_q.empty())
                       break;
                    else
                        a_index = before_q.front();
                }
            }
        }

        // M창고 단계1, M창구 남은 시간 비교해서 빼준다!
        for(int i=1;i<=M;i++){
            if(bi[i].exist==true){
                bi[i].spare_time--;
                if(bi[i].spare_time==0){
                    bi[i].exist = false;
                }
            }
        }
        // M창고 단계2, 중간에 기다리는 고객 M창구에 넣어준다.
        if(!after_q.empty()) {
            int b_index = after_q.front();
            for (int i = 1; i <= M; i++) {
                if (bi[i].exist != true) {
                    bi[i].exist = true;
                    bi[i].spare_time = bi[i].time;
                    bi[i].num = b_index;
                    ki[b_index].b_num = i;
                    after_q.pop();
                    if(after_q.empty())
                        break;
                    else
                        b_index = after_q.front();
                }
            }
        }
        for(int i=1;i<=K;i++){
            if(ki[i].b_num){
                check_middle = true;
                break;
            }else{
                false;
            }
        }

        //처음과 중간에 기달리는 사람 없으면 그거 다 있는 거니깐 바로 빼준다!
//        if(before_q.empty()&&after_q.empty()&&ki[1].time<=time)
        bool check_final = false;
        if(check_middle&&after_q.empty()){
            for(int i=1;i<=N;i++){
                if(ai[i].exist){
                    check_final=false;
                    break;
                }else{
                    check_final=true;
                }
            }
        }

        if(check_final)
            break;
        time++;
    }
}

int main(){
    int t;
    int c = 0;
    scanf("%d",&t);
    while(c++<t){
        memset(ai,0,sizeof(ai));
        memset(bi,0,sizeof(bi));
        memset(ki,0,sizeof(ki));
        Node node;
        ans = 0;
        scanf("%d %d %d %d %d",&N,&M,&K,&A,&B);

        for(int i=1;i<=N;i++)
            scanf("%d",&ai[i].time);
        for(int i=1;i<=M;i++)
            scanf("%d",&bi[i].time);
        for(int i=1;i<=K;i++){
            int temp_time;
            scanf("%d",&temp_time);
            node.num = i;
            node.time = temp_time;
            ki[i] = node;
        }

        solve();
        bool check_not = true;
        for(int i=1;i<=K;i++){
            if(ki[i].a_num==A&&ki[i].b_num==B){
//                printf(" %d ",i);
                ans+=i;
                check_not = false;
            }
        }

        if(check_not)
            ans = -1;

        printf("#%d %d\n",c,ans);
    }
    return 0;
}