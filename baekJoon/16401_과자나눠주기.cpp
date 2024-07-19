#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 1000001;
int M,N;
int len[MX];
bool func(int x){
    if(x == 0) return true;
    long long cnt = 0;
    for(int i=0;i<N;i++){
        cnt += len[i]/x;
    }
    return cnt >= M;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> M>>N;

    for(int i=0;i<N;i++){
        cin >> len[i];
    }
    int lef = 0;
    int rig = *max_element(len,len+N);

    while(lef<rig){
        int mid = (lef+rig+1)/2;
        if(func(mid)) lef = mid;
        else rig = mid-1;
    }
    cout << lef << '\n';
    return 0;
}