#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;
    vector<int>v;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    for(int i=0;i<M;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());

    for(int s:v){
        cout << s << ' ';
    }
    return 0;
}