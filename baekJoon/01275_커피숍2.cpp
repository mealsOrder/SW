#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
using ll = long long;
int N,Q;
vector<ll>v;
vector<ll>tree;

ll init(int node,int s, int e){
    if(s==e) return tree[node] = v[s];
    int mid=(s+e)/2;

    return tree[node] = init(node*2,s,mid) + init(node*2+1,mid+1,e);
}
// l        r
//    s   e
ll query(int node,int s,int e,int l,int r){
    if(r<s||e<l) return 0;
    if(l<=s&&e<=r) return tree[node];
    int mid=(s+e)/2;

    return query(node*2,s,mid,l,r) + query(node*2+1,mid+1,e,l,r);
}

ll update(int node,int s,int e,int idx,ll val){
    if(idx<s || e<idx) return tree[node];
    if(s==e) return tree[node]=val;
    int mid=(s+e)/2;

    return tree[node] = update(node*2,s,mid,idx,val) + update(node*2+1,mid+1,e,idx,val);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> Q;

    v.resize(N+1);
    tree.resize(4*N);

    for(int i=1;i<=N;i++) cin >> v[i];

    init(1,1,N);
    while(Q--){
        int x,y,a;
        ll b;
        cin >> x >> y >> a >> b;
        if(x>y)swap(x,y);
        cout << query(1,1,N,x,y) << '\n';
        update(1,1,N,a,b);
    }
    return 0;
}
