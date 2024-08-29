#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int MX = 50;
int N;
vector<int>p;
vector<int>m;
long long ans;
void func(vector<int>&v){
    while(1<v.size()){
        ans += *(v.end()-1) * *(v.end()-2);
        v.pop_back();
        v.pop_back();
    }
    if(v.size()) ans+=v[0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        if(a <= 0) m.push_back(a);
        else if(a == 1) ans++; 
        else p.push_back(a);
    }

    sort(p.begin(),p.end());
    sort(m.begin(),m.end(),greater<>());

    func(p);
    func(m);

    cout << ans << '\n';

    return 0;
}