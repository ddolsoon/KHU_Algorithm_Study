#include <iostream>
#include <cstring>
#define SIZE 1001
using namespace std;

int max_value;
int lcs[SIZE][SIZE];

int main(){
    int t;
    int c= 0;
    scanf("%d",&t);
    while(c++<t){
        string str1;
        string str2;
        cin>>str1>>str2;


        int n = str1.length();
        int m = str2.length();

        /*
         * 좋은 문제드아
         *
         */
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    lcs[i][j]=lcs[i-1][j-1]+1;
                }else{
                    lcs[i][j] = max(lcs[i][j-1],lcs[i-1][j]);
                }
            }
        }

        printf("#%d %d\n",c,lcs[n][m]);
    }

    return 0;
}