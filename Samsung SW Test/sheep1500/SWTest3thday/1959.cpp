#include <iostream>

using namespace std;

int A[20];
int B[20];

int cal_twoarray(int n,int m){
    int max;
    int c = 0;
    if(n>m){
        while(c<=n-m){
            int sum = 0;
            for(int i=0;i<m;i++){
                sum +=(B[i]*A[i+c]);
            }
            if(max<sum)
                max = sum;
            c++;
        }
    }else{
        while(c<=m-n){
            int sum = 0;
            for(int i=0;i<n;i++){
                sum +=(A[i]*B[i+c]);
            }
            if(max<sum)
                max = sum;
            c++;
        }
    }
    return max;

}

int main() {
    int t,count=0;
    cin>>t;
    while(count++<t){
        int N,M;
        cin>>N>>M;

        for(int i=0;i<N;i++)
            cin>>A[i];
        for(int i=0;i<M;i++)
            cin>>B[i];


        cout<<"#"<<count<<" "<<cal_twoarray(N,M)<<endl;

    }
    return 0;
}