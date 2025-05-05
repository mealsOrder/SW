#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
vector<ll>arr;
vector<ll>tree;
int N,M,K;

ll init(int node,int s,int e){
    if(s==e) return tree[node] = arr[s];
    int mid = (s+e)/2;

    return tree[node] = init(node*2,s,mid) + init(node*2+1,mid+1,e);
}

// l                r
//      s       e
ll query(int node,int s,int e,int l,int r){
    // 범위 안겹칠때
    if( r<s || e<l) return 0;
    if( l <= s && e <= r) return tree[node];
    int mid = (s+e)/2;

    return query(node*2,s,mid,l,r) + query(node*2+1,mid+1,e,l,r);
}

// init + query
ll update(int node,int s,int e,int idx,ll val){
    // idx 범위 벗어날때
    if(idx < s || e < idx) return tree[node];
    if(s == e) return tree[node] = val;
    int mid = (s+e)/2;

    return tree[node] = update(node*2,s,mid,idx,val) + update(node*2+1,mid+1,e,idx,val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    arr.resize(N+1);
    tree.resize(4*(N+1));
    int T = M+K;
    for(int i=1;i<=N;i++) cin >> arr[i];

    init(1,1,N);

    while(T--){
        int a,b;
        ll c;
        cin >> a >> b >> c;

        if(a == 1){
            arr[b] = c;
            update(1,1,N,b,c);
        }
        else if( a == 2){
            cout << query(1,1,N,b,(int)c) << '\n';
        }
    }
    return 0;
}