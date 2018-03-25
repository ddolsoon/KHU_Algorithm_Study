#include <iostream>
#include <cstring>
#define SIZE 101
#define SIZE_K 1001
using namespace std;

int arrV[SIZE];
int arrC[SIZE];
int ans[SIZE][SIZE_K];
int N,K;

// 완전탐색으로 풀었을 경우, 제한시간 초과 걸림 이렇게도 풀려요!
//void dfs(int sum,int total_index,int index){
//
//    memo[index] = 1;
//    sum+=arrC[index];
//
//    if(sum > max_value){
//        max_value= sum;
//    }
//
//    for(int i=index+1;i<N;i++){
//        if(memo[i]==0&&total_index+arrV[i]<=K){
//            bfs(sum,total_index+arrV[i],i);
//        }
//    }
//    memo[index] = 0;
//}



int main(){
    int t;
    int c= 0;
    scanf("%d",&t);
    while(c++<t){
        scanf("%d %d",&N,&K);

        for(int i=1;i<=N;i++){
            scanf("%d %d",&arrV[i],&arrC[i]);
        }

        for(int i=1;i<=N;i++){
            for(int j=1;j<=K;j++){
                /*
                 * 이 부분이 가장 중요한 부분!!
                 * ans[i][j] 중 i는 해당 인덱스의 가방 부피
                 * ans[i][j] 중 j는 총 부피
                 * ans[i][j] 의 값은 i , j 일 때 가장 큰 값의 총 가치
                 * 즉 ans[4][5]=6 는 4번째 가방 부피일 때 가방 부피 총합 5의 가치가 6
                 *
                 * ans[i-1][j-arrV[i]], i의 가방 부피 만큼 뺐을 때 최대 가치에 arrC[i] 를 더해준 것과 비교
                 */
                if(j-arrV[i]>=0)
                    ans[i][j] = max(arrC[i]+ans[i-1][j-arrV[i]],ans[i-1][j]);
                else
                    ans[i][j] = ans[i-1][j];

            }
        }
        printf("#%d %d\n",c,ans[N][K]);
    }

    return 0;
}