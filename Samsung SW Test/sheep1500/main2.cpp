//
// Created by jameskang on 18. 3. 14.
//
#include <iostream>
using namespace std;

int main(){

    int test_case_num;
    cin>> test_case_num;
    int c = 0;
    while(test_case_num--) {
        int N, K;
        cin >> N >> K;

        int **puzzle_array = new int *[N];
        for (int i = 0; i < N; i++){
            puzzle_array[i] = new int[N];
            for(int j=0;j<N;j++){
                cin>>puzzle_array[i][j];
            }
        }

        int count = 0;
        for(int w=0;w<N;w++){
            for(int i=0;i+K<=N;i++){
                int last_index =i+K-1;
                bool check_puzzle_wide = true;
                for(int j=i;j<=last_index;j++){
                    if(puzzle_array[w][j]==0){
                        check_puzzle_wide = false;
                    }
                    if(i>0 && puzzle_array[][]){

                    }
                }
                if(last_index+1<N){
                    if(puzzle_array[w][last_index+1]==1){
                        check_puzzle_wide = false;
                    }
                }

                if(check_puzzle_wide){
                    cout<<w<<" "<<last_index+1<<endl;
                    count++;
                }

            }
        }
        cout<<"#"<<++c<<" "<<count<<endl;


        // 동적 배열 삭제 방법
        for (int i = 0; i < N; i++) {
            delete[] puzzle_array[i];
        }
        delete[] puzzle_array;
    }
    return 0;
}
