//
// Created by jameskang on 18. 4. 4.
//
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int ans;
int day,month_1,month_3,year;

int month_arr[13];
int dp[13];

int main(){

    int t;
    int c =0;
    scanf("%d",&t);
    while(c++<t){
        fill_n(month_arr+1,12,0);
        fill_n(dp+1,12,0);
        scanf("%d %d %d %d",&day,&month_1,&month_3,&year);
        for(int i=1;i<=12;i++)
            scanf("%d",&month_arr[i]);


        for(int i=1;i<=12;i++){
            if(i<3){
                dp[i] = min(dp[i-1]+month_1,dp[i-1]+day*month_arr[i]);
            }else{
                dp[i] = min(dp[i-1]+month_1,dp[i-1]+day*month_arr[i]);
                dp[i] = min(dp[i],dp[i-3]+month_3);
            }
        }
        if(d[12]>year)dp[12] =year;
        printf("#%d %d\n",c,dp[12]);
    }
    return 0;
}
