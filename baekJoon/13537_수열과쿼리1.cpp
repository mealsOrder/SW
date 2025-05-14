#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<cstring>
using namespace std;

const int MX = 100001;
const int INF = INT_MAX;
vector<int>arr;
vector<int>tree[4*MX];
int N,M;

void init(int node,int s, int e){
    if(s == e){
        tree[node].push_back(arr[s]);
        return;
    }
    int mid = (s+e)/2;
    init(node*2,s,mid);
    init(node*2+1,mid+1,e);

    // 두 구간을 병합
    tree[node].resize(e - s + 1);
    merge(tree[node * 2].begin(), tree[node * 2].end(),
          tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(),
          tree[node].begin());
}

//    s   e
// l         r
// s~e구간 중에서 l~r 사이에 있는 값들중, k보다 큰 개수
int query(int node,int s,int e,int l,int r,int k){
    if(r<s || e<l) return 0;
    if(l<=s&&e<=r){
        // 현재 노드에서 k초과 값 개수 세기
        return tree[node].end() - upper_bound(tree[node].begin(),tree[node].end(),k);
    }
    int mid = (s+e)/2;

    return query(node*2,s,mid,l,r,k) + query(node*2+1,mid+1,e,l,r,k);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    arr.resize(N+1);

    for(int i=0;i<N;i++)cin >> arr[i];

    cin >> M;

    init(1,0,N-1);
    while(M--){
        int ans = 0;

        int i,j,k;
        cin >> i >> j >> k;

        cout << query(1,0,N-1,i-1,j-1,k) << '\n';

    }
    return 0;
}
