#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long N,T,P;
    cin >> N;
    vector<long long>t(6);
    for(int i=0;i<6;i++){
        cin >> t[i];
    }
    cin >> T>>P;

    long long tOrder=0;
    for(int i=0;i<6;i++){
        tOrder += ceil((double)t[i] / T);
    }
    long long pOrders = N/P;
    long long pOrder = N%P;
    cout << tOrder << '\n';
    cout << pOrders << " " << pOrder << '\n';

    return 0;
}