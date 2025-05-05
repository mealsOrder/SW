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

int init(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];
    int mid = (start+end)/2;
    return tree[node] = min( init(node*2,start,mid), init(node*2+1,mid+1,end));
}

//  l               r
//      s       e
int query(int node, int start, int end, int left, int right){
    if(right < start || end < left) return INF;

    if(left <=start && end <= right) return tree[node];

    int mid = (start+end)/2;
    return min( query(node*2,start,mid,left,right) , query(node*2+1,mid+1,end,left,right));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> M;

    arr.resize(N);
    tree.resize(4*N);

    for(int i=0;i<N;i++) cin >> arr[i];
    init(1,0,N-1);
    while(M--){
        int a,b;
        cin >> a >> b;

        cout << query(1,0,N-1,a-1,b-1) << '\n';
    }

    return 0;
}