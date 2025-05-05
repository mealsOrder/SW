#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;
vector<int>ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;

    for(int i=N;i>=1;i--){
        int res = i;
        int k = i;
        while(k>0){
            res+= k%10;
            k/=10;
        }
        if(res == N) ans.push_back(i);
    }

    if(ans.empty()) cout << 0 <<'\n';
    else cout << *min_element(ans.begin(),ans.end());
    return 0;
}