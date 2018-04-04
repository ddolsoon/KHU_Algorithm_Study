//
// Created by jameskang on 18. 4. 4.
//
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int ans;
int day,month_1,month_3,year;

int month_arr[13];

void dfs(int month,int sum){
    if(month>=13){
        if(sum<ans) ans = sum;
        return;
    }
    //1일 이용권 사용
    dfs(month+1,sum+month_arr[month]*day);
    //1달 이용권 사용
    dfs(month+1,sum+month_1);
    //3달 이용권 사용
    dfs(month+3,sum+month_3);
    //1년 이용권 사용
}

int main(){

    int t;
    int c =0;
    scanf("%d",&t);
    while(c++<t){
        scanf("%d %d %d %d",&day,&month_1,&month_3,&year);
        for(int i=1;i<=12;i++)
            scanf("%d",&month_arr[i]);

        ans = year;
        dfs(1,0);

        printf("#%d %d\n",c,ans);
    }
    return 0;
}
