//
// Created by jameskang on 18. 3. 14.
//
#include <iostream>
using namespace std;

int puzzle_array[15][15];

int word_check(int N,int K){
    int count=0,x,y;
    for(int i=0;i<N;i++){
        for(int j=0;j<=N-K;j++){
            for(x =j;x<N;x++){
                if(puzzle_array[i][x]==0)
                    break;
            }
            if(x-j == K)
                count++;
            else if(x-j>K)
                j = x;
        }
        for(int m=0;m<=N-K;m++){
            for(y =m;y<N;y++){
                if(puzzle_array[y][i]==0)
                    break;
            }
            if(y-m == K)
                count++;
            else if(y-m>K)
                m = y;
        }
    }
    return count;
}

int main(){

    int test_case_num;
    cin>> test_case_num;
    int c = 0;
    while(++c <= test_case_num) {
        int N, K;
        int word_count = 0;
        scanf("%d %d",&N,&K);

        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&puzzle_array[i][j]);


        word_count = word_check(N,K);
        printf("#%d %d\n",c,word_count);
    }
    return 0;
}

