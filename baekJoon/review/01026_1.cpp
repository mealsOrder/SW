#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,ans;
vector<int>a;
vector<int>b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;

    for(int i=0;i<N;i++){
        int n;
        cin >> n;
        a.push_back(n);
    }        
    
    for(int i=0;i<N;i++){
        int n;
        cin >> n;
        b.push_back(n);
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());

    for(int i=0;i<N;i++){
        ans += (a[i]*b[i]);
    }
    cout << ans <<'\n';
    return 0;
}