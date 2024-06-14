#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 50;
int N,M;
int arr[MX];
bool flag[MX];
void back(int x){
    if(x==M){
        for(int i=0;i<M;i++) cout << arr[i] << " ";
        cout << '\n';
        return;
    }
    for(int i=1;i<=N;i++){
        if(!flag[i]){
            arr[x] = i;
            flag[i] = 1;
            back(x+1);
            flag[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    back(0);

    return  0;
}