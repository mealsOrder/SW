#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int INF = INT_MAX;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a;
    string b;

    cin >> a >> b;

    int sub = b.size() - a.size();
    
    for(int i=0;i<sub+1;i++){
        int cnt = 0;
        for(int j=0;j<a.size();j++){
            if(a[j]!=b[i+j]){
                cnt++;
            }
        }
        INF = min(cnt,INF);
    }
    cout << INF << '\n';
    return 0;
}