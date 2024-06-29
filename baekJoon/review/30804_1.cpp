#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int>S(N);
    for(int i=0;i<N;i++)cin >>S[i];

    map<int,int>tangHuru;
    int lef=0,rig=0,maxLen=0;

    while(rig<N){
        tangHuru[S[rig]]++;
        while(tangHuru.size()>2){
            if(--tangHuru[S[lef]] == 0){
                tangHuru.erase(S[lef]);
            }
            lef++;
        }
        maxLen = max(maxLen, rig - lef + 1);
        rig++;
    }
    cout << maxLen << '\n';
    return 0;
}