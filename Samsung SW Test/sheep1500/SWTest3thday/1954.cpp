#include <iostream>
#include <cstring>

using namespace std;


int main() {
    int t;
    int c = 0;
    cin >>t;
    while(c++ < t){
        int arr[10][10]={0,};

        int n;
        cin>>n;
        int direct = 0;
        int num = 1;
        int row = 0,col = 0;
        int count = n;
        memset(arr,0,sizeof(arr));

        while(direct<2*n-1){
            if(direct%4==0){
                for(int i=1;i<count;i++){
                    arr[row][col++] = num++;
                }
                arr[row][col] = num++;
                row++;
            }else if(direct%4==1){
                for(int i=1;i<count;i++){
                    arr[row++][col] = num++;
                }
                arr[row][col] = num++;
                col--;
            }else if(direct%4==2){
                for(int i=1;i<count;i++){
                    arr[row][col--] = num++;
                }
                arr[row][col] = num++;
                row--;
            }else if(direct%4==3){
                for(int i=1;i<count;i++){
                    arr[row--][col] = num++;
                }
                arr[row][col] = num++;
                col++;
            }

            if(direct%2==0){
                count--;
            }
            direct++;
        }
        cout<<"#"<<c<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}

