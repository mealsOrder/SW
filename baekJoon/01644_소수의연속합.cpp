#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<cstring>
using namespace std;

int N;
vector<int>v;
vector<int>tree;
void prim(int x){
    int cnt = 0;
    if(x == 1) return;
    for(int i = 2;i<=N;i++){
        if(x%i == 0) cnt++;
    }
    if(cnt == 1) v.push_back(x);
}

void func(int x){
    vector<bool>isPrime(N+1,1);
    isPrime[0]=isPrime[1] = 0;

    for(int i=2;i<=N;i++){
        if(isPrime[i])v.push_back(i);
        for(int p:v){
            if(i*p>N)break;
            isPrime[i*p]=0;
            if(i%p == 0) break;
        }
    }
}

int init(int node,int s,int e){
    if(s == e) return tree[node] = v[s];
    int mid = (s+e)/2;

    return tree[node] = init(node*2,s,mid) + init(node*2+1,mid+1,e);
}
//  s   e
//l         r
int query(int node,int s,int e,int l,int r){
    if(r<s || e <l) return 0;
    if(l<=s && e <=r) return tree[node];
    int mid=(s+e)/2;

    return query(node*2,s,mid,l,r) + query(node*2+1,mid+1,e,l,r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    func(N);
    if(v.empty()){
        cout << 0 << '\n';
        return 0;
    }
    tree.resize(v.size()*4);

    init(1,0,v.size()-1);
    int ans = 0;
    for(int i=0;i<v.size();i++){
        for(int j=i;j<v.size();j++){
            int sum = query(1, 0, v.size() - 1, i, j);
            if(sum > N)break;
            if(sum == N)ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
