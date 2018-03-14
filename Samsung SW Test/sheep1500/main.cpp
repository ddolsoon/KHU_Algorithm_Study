#include <iostream>

using namespace std;

int main() {
    int test_case_num;
    cin>> test_case_num;
    int count = 0;
    while(test_case_num--){
        int ten = 10;
        int ten_array[10];
        for(int i=0;i<ten;i++)
            cin >>ten_array[i];

        int min = 0;
        int max = 0;
        for(int i=0;i<ten;i++){
            if(ten_array[min]>ten_array[i])
                min = i;
            if(ten_array[max]<ten_array[i])
                max = i;
        }
        int sum = 0;
        int divided_count = 8;
        for(int i=0;i<ten;i++){
            if(i!=min && i!=max){
                sum += ten_array[i];
            }
        }
        double answer = sum/(double)divided_count;

        // 소수점 고정하고 몇째짜리 까지 정하는 방법,
        // 반올림은 <cmath>의 floor로 해도 되지만 이렇게 해도 나머지 수에서 반올림한다!
        cout<<fixed;
        cout.precision(0);
        cout<<"#"<<++count<<" "<<answer<<endl;
    }


    return 0;
}