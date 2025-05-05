#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;
const int MX = 101;
int card[101];
vector<int>ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    cin >> N >> M;

    for(int i=0;i<N;i++) cin >> card[i];

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(i==j || j==k || i==k)continue;
                int sum = card[i]+card[j]+card[k];
                if(sum <= M) ans.push_back(sum);
            }
        }
    }

    cout << *max_element(ans.begin(),ans.end());
    return 0;
}