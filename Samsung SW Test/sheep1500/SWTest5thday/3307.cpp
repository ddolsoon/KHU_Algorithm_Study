#include <iostream>
#include <cstring>
#define SIZE 1001
using namespace std;

int array[SIZE];
int d[SIZE];

int main(){
    int t;
    int c= 0;
    scanf("%d",&t);
    while(c++<t){
        memset(d,0,sizeof(d));
        memset(array,0,sizeof(array));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&array[i]);

        d[1]=1;
        for(int i=2;i<=n;i++){
            d[i]=1;
//            for(int j=i-1;j>=0;j--){
            for(int j=1;j<i;j++){
                if(array[i]>array[j]&&d[i]<d[j]+1){
                    d[i] = d[j]+1;
                }
            }
        }

        printf("#%d %d\n",c,d[n]);
    }

    return 0;
}