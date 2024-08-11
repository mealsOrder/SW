#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    vector<int>v;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());
    int sum=0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<i+1;j++){
            sum+=v[j];
        }
    }
    cout << sum << '\n';
    return 0;
}