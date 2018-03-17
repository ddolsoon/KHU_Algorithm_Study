#include <iostream>

using namespace std;

int arr[1000001];

int main() {
    int t;
    cin>>t;
    int c = 0;
    while(c++<t){
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
            cin>>arr[i];

        int max_index = n-1;
        int start_index = 0;
        long long sum = 0;

        do{
            for(int i=start_index;i<n;i++){
                if(arr[max_index]<=arr[i]){
                    max_index = i;
                }
            }
            for(int i=start_index;i<max_index;i++){
                sum+=(arr[max_index]-arr[i]);
            }
            if(max_index==0 || max_index==n-1){
                start_index = n;
            }else{
                start_index = max_index+1;
                max_index = n-1;
            }
        } while(start_index<n);

        cout<<"#"<<c<<" "<<sum<<endl;
    }
    return 0;
}

