#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
const pair<int,int>INF = {2e9, 2e9}; // 값, 인덱스
int N,M;
vector<int>a;
vector<pair<int,int>>tree;
/**
 * @brief 수열과 쿼리 문제 cf) sch314 풀이 참고해보기
 * 
 * @param node 
 * @param s 
 * @param e 
 */
pair<int,int>init(int node,int s,int e){
    if(s == e) return tree[node] = {a[s],s};
    int mid = (s+e)/2;

    pair<int,int>l = init(node*2, s, mid);
    pair<int,int>r = init(node*2+1,mid+1,e);
    return tree[node] = min(l,r);
}
//l         r
//   s    e
pair<int,int>query(int node,int s,int e,int l,int r){
    if(r<s || e<l)return INF;
    if(l<=s && e<=r)return tree[node];
    int mid = (s+e)/2;

    return min(query(node*2,s,mid,l,r),query(node*2+1,mid+1,e,l,r));
}

pair<int,int>update(int node,int s,int e,int idx,int val){
    if(idx<s || e<idx) return tree[node];
    if(s==e) return tree[node]={val,idx};
    int mid=(s+e)/2;

    return tree[node] = min(update(node*2,s,mid,idx,val),update(node*2+1,mid+1,e,idx,val));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    a.resize(N+1);
    tree.resize(4*(N+1));

    for(int i=1;i<=N;i++){
        cin >> a[i];
    }

    cin >> M;
    init(1,1,N);
    while(M--){
        int x,y,z;
        cin >> x >> y >> z;

        if(x == 1){
            update(1,1,N,y,z);
        }
        else if(x == 2){
            cout << query(1,1,N,y,z).second << '\n';
        }
    }
    return 0;
}