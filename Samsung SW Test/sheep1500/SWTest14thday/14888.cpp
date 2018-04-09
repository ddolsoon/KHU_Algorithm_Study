//
// Created by jameskang on 18. 4. 10.
//

#include <iostream>
#include <math.h>
#include <cstring>
#define MAX_SIZE 11

using namespace std;

int num_array[MAX_SIZE];
int cal_array[4];
int n;
int max_value = -1000000001;
int min_value = 1000000001;


void dfs(int d, int total){
    if(d==n){
        if(total>=max_value)
            max_value = total;
        if(total<=min_value)
            min_value = total;
    }

    if(cal_array[0]){
        cal_array[0]--;
        dfs(d+1,total+num_array[d]);
        cal_array[0]++;
    }
    if(cal_array[1]){
        cal_array[1]--;
        dfs(d+1,total-num_array[d]);
        cal_array[1]++;
    }
    if(cal_array[2]){
        cal_array[2]--;
        dfs(d+1,total*num_array[d]);
        cal_array[2]++;
    }
    if(cal_array[3]){
        cal_array[3]--;
        dfs(d+1,total/num_array[d]);
        cal_array[3]++;
    }

}

int t;
int main(){
    scanf("%d",&t);
    int c=0;
    while(c++<t) {
        memset(cal_array,0,sizeof(cal_array));
        max_value = -1000000001;
        min_value = 1000000001;

        scanf("%d", &n);
        for (int i = 0; i < 4; i++)
            scanf("%d", &cal_array[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &num_array[i]);

        dfs(1, num_array[0]);

        printf("#%d %d\n",c, max_value-min_value);

    }
    return 0;
}