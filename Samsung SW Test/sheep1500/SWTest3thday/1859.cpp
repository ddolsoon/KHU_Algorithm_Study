#include <iostream>

using namespace std;

int arr[1000000];

long long rich(int start,int max_index,int n){
    if(start==max_index)
        return 0;

    long long sum = 0;
    for(int i=start;i<max_index;i++){
        sum+=(arr[max_index]-arr[i]);
    }
    if(max_index==(n-1))
        return sum;

    int index = max_index+1;
    for(int i=max_index+1;i<n;i++){
        if(arr[index]<=arr[i])
            index = i;
    }
    return sum+rich(max_index+1,index,n);
}

int main() {
    int t;
    cin>>t;
    int c = 0;
    while(c++<t){
        long long n;
        cin>>n;

        for(int i=0;i<n;i++)
            cin>>arr[i];


        int max_index = 0;
        long long sum = 0;
        for(int i=1;i<n;i++){
            if(arr[max_index]<=arr[i]){
                max_index = i;
            }
        }

        sum = rich(0,max_index,n);

        printf("#%d %ld",c,sum);
    }
    return 0;
}

