#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >>N;
    vector<int>S(N);
    for(int i=0;i<N;i++)cin >> S[i];

    map<int,int>fruitHuru;
    int lef=0,rig=0,mxLen = 0;
    while(rig < N){
        fruitHuru[S[rig]]++;
        while(fruitHuru.size()>2){
            if(--fruitHuru[S[lef]] == 0){
                fruitHuru.erase(S[lef]);
            }
            lef++;
        }
        mxLen = max(mxLen, rig - lef + 1);
        rig++;
    }
    cout << mxLen << '\n';
    return 0;
}