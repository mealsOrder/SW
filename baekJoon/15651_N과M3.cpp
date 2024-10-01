#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N,M;
int arr[10];
bool vis[10];
void back(int x){
    if(x == M){
        for(int i=0;i<M;i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    else{
        for(int i=1;i<=N;i++){
            arr[x] = i;
            back(x+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N>>M;
    
    back(0); 
    return 0;
}