#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

typedef long long ll;

vector<ll>tree,arr,lazy;
int N,M,K;

ll init(int node,int s,int e){
    if(s == e) return tree[node] = arr[s];
    int mid = (s+e)/2;

    return tree[node] = init(node*2,s,mid) + init(node*2+1,mid+1,e);
}

void propagate(int node,int s,int e){
    if(lazy[node]!= 0){
        tree[node] += (e-s+1)*lazy[node]; // lazy값 반영
        if(s!=e){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node]=0;
    }
}
//l       r
//  s   e
ll query(int node,int s,int e,int l,int r){
    propagate(node,s,e);
    if(r<s||e<l) return 0;              // 노겹
    if(l<=s && e <=r) return tree[node];// 겹침
    int mid=(s+e)/2;
    return query(node*2,s,mid,l,r) + query(node*2+1,mid+1,e,l,r);
}

void update(int node,int s,int e,int l,int r,ll v){
    propagate(node,s,e);
    if(r<s||e<l) return;              // 노겹
    if(l<=s && e <=r){                // 겹침
        lazy[node] += v;
        propagate(node,s,e);
        return;
    }
    int mid=(s+e)/2;
    update(node*2,s,mid,l,r,v);
    update(node*2+1,mid+1,e,l,r,v);
    tree[node] = tree[node*2]  + tree[node*2+1] ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    int T = M+K;
    arr.resize(N+1);
    tree.resize((N+1)*4);
    lazy.resize((N+1)*4);
    for(int i=1;i<=N;i++) cin >> arr[i];

    init(1,1,N);
    while(T--){
        int a,b,c;
        ll d;
        cin >> a;

        if(a == 1){
            cin >> b >> c >> d;
            // [b c] 구간에 모든수에 d 더하기
            update(1,1,N,b,c,d);
        }
        else{
            cin >> b >> c;
            // [b c] 구간의 합 구하기
            cout << query(1,1,N,b,c) << '\n';
        }
    }
    return 0;
}