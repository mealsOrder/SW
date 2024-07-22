#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
const int MX = 10;
int N,M;
int arr[MX];
bool vis[MX];
set<vector<int>>s;
void func1(int x){
    if(x == N){
        for(int i=0;i<N;i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=6;i++){
        arr[x]=i;
        func1(x+1);
    }
}

void func2(int x){
    if(x == N){
        vector<int> com(arr,arr+N);
        sort(com.begin(),com.end());
        if(s.find(com) == s.end()){
            s.insert(com);
            for(int i=0;i<N;i++){
                cout << arr[i] << " ";
            }
            cout << '\n';
        }
        return;
    }
    for(int i=1;i<=6;i++){
        arr[x]=i;
        func2(x+1);
    }
}

void func3(int x){
    if(x == N){
        for(int i=0;i<N;i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=6;i++){
        if(!vis[i]){
            arr[x]=i;
            vis[i] = true;
            func3(x+1);
            vis[i] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    //fill(arr,arr+MX,0);
    if(M == 1)func1(0);
    if(M == 2)func2(0);
    if(M == 3)func3(0);

    return 0;
}