#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
#include<climits>
using namespace std;

const int INF = INT_MAX;

int N,M;
vector<int>arr;
vector<int>tree;

int init(int node,int s, int e){
    if(s == e) return tree[node] = arr[s];
    int mid = (s+e)/2;
    return tree[node] = min( init(node*2,s,mid) , init(node*2+1,mid+1,e));
}


//    s      e
//l              r
int query(int node,int s,int e,int l,int r){
    if(r<s || e < l) return INF;
    if(l<=s && e<=r) return tree[node];
    int mid = (s+e)/2;
    return min( query(node*2,s,mid,l,r), query(node*2+1 ,mid+1,e,l,r) );
}

// init 과 query 를 합쳐 놓은 것처럼 구현 하면 됨
int update(int node,int s,int e,int idx,int v){
    if(idx<s || e<idx) return tree[node]; // 인덱스가 범위 밖이면
    if(s == e) return tree[node] = v;
    int mid = (s+e)/2;

    return tree[node] = min( update(node*2,s,mid,idx,v),
                             update(node*2+1,mid+1,e,idx,v) );
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N;

    arr.resize(N+1);
    tree.resize(4*(N+1));
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    init(1,1,N);
    cin >> M;

    while(M--){
        int op;
        cin >> op;

        switch (op)
        {
        case 1:
            int idx,v;
            cin >> idx >> v;
            arr[idx] = v;
            update(1,1,N,idx,v);
            break;
        
        case 2:
            int a,b;
            cin >> a >> b;
            cout << query(1,1,N,a,b) << '\n';
            break;
        }
    }
    return 0;
}