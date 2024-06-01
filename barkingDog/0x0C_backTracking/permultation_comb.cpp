#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 순열
    int a[3]={1,2,3};
    do{
        for(int i=0;i<3;i++){
            cout << a[i];
        }
        cout << '\n';
    }while(next_permutation(a,a+3));

    // 조합 4개에서 2개 뽑는 문제
    int b[4] = {0,0,1,1};
    do{
        for(int i=0;i<4;i++){
            if(b[i] == 0){
                cout << i+1;
            }
        }
        cout << '\n';
    }while(next_permutation(b,b+4));

    // 조합 5개에서 3개 뽑는 문제
    int c[5] = {0,0,0,1,1};
    do{
        for(int i=0;i<5;i++){
            if(c[i] == 0){
                cout << i+1;
            }
        }
        cout << '\n';
    }while(next_permutation(c,c+5));
    return 0;
}