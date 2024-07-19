#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 1001;
int N;
int u[MX];
vector<int> hap;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> u[i];
    }
    sort(u,u+N);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            hap.push_back(u[i]+u[j]);
        }
    }
    sort(hap.begin(),hap.end());

    for(int i=N-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(binary_search(hap.begin(),hap.end(),a[i]-a[j])){
                cout << u[i];
                return 0;
            }
        }
    }
    return 0;
}