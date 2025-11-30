#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
using ll = long long;

const int MOD = 1000000007;
vector<int>v;
vector<ll>tree;
int N,M,K;
ll init(int node,int s,int e){
    if(s == e) return tree[node] = v[s];
    int mid = (s+e)/2;

    return tree[node] = (init(node*2,s,mid) * init(node*2+1,mid+1,e)) % MOD;
}

//l        r
//  s   e
ll query(int node,int s,int e,int l,int r){
    if(r<s||e<l) return 1;
    if(l<=s&&e<=r) return tree[node];
    int mid = (s+e)/2;
    return (query(node*2,s,mid,l,r) * query(node*2+1,mid+1,e,l,r))%MOD;
}

ll update(int node,int s,int e,int idx,int val){
    if(idx<s || e <idx) return tree[node];
    if(s == e) return tree[node] = val;
    int mid = (s+e)/2;
    return tree[node] = (update(node*2,s,mid,idx,val) * update(node*2+1,mid+1,e,idx,val) )%MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    int T = M+K;
    v.resize(N+1);
    tree.resize(4*N);
    for(int i=0;i<N;i++){
        cin >> v[i];
    }

    init(1,0,N-1);
    while(T--){
        int a,b,c;
        cin >> a >> b >> c;

        // 변경
        if(a == 1){
            update(1,0,N-1,b-1,c);
        }
        // 곱
        else if(a == 2){
            cout << query(1,0,N-1,b-1,c-1)<< '\n';
        }
    }
    return 0;
}
