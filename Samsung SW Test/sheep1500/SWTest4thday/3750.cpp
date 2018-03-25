#include <iostream>
#include <cstring>
using namespace std;

char array[18];
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    int c = 0;
    scanf("%d",&t);
    while(c++<t){
        string f;
        scanf("%s",array);
        int temp=10;
        while(temp>=10){
            temp=0;
            for(int i=0;i<array[i]!=NULL;i++){
                temp+=(int)(array[i]-'0');
            }
            memset(array,NULL,sizeof(char)* 18);
            sprintf(array,"%d",temp);
        }

        printf("#%d %d\n",c,temp);
    }
    return 0;
}