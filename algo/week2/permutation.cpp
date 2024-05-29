#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int N,R;
int res[20];
void permu(int x){

    if(x>=R){
        bool flag = false;
        for(int i=0;i<R;i++){
            for(int j=0;j<R;j++){
                if(i!=j && res[i] == res[j]){
                    flag = true;
                }
            }
        }
        if(flag == false){
            for(int i=0;i<R;i++) cout << res[i]+'a';
            cout << '\n';
        }
    }
    else{
        for(int i=0;i<N;i++){
            res[x] = i;
            permu(x+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> R;
    permu(0);
    return 0;
}