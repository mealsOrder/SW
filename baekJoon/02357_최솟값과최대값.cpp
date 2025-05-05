#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
#include<climits>
using namespace std;

const int INF = INT_MAX;
const int NINF = INT_MIN;
int N,M;
vector<int>arr;
vector<int>minTree;
vector<int>maxTree;
int initMin(int node,int s,int e){
    if(s==e) return minTree[node] = arr[s];
    int mid = (s+e)/2;
    return minTree[node] =  min( initMin(node*2,s,mid), initMin(node*2+1,mid+1,e));
}

//      s       e
//  l                r
int minQuery(int node,int s,int e,int l,int r){
    if(r<s || e<l) return INF;
    if(l<=s && e<=r) return minTree[node];

    int mid = (s+e)/2;
    return min( minQuery(node*2,s,mid,l,r) , minQuery(node*2+1,mid+1,e,l,r));
}

int initMax(int node,int s,int e){
    if(s==e) return maxTree[node] = arr[s];
    int mid = (s+e)/2;
    return maxTree[node] =  max( initMax(node*2,s,mid), initMax(node*2+1,mid+1,e));
}

int maxQuery(int node,int s,int e,int l,int r){
    if(r<s || e<l) return NINF;
    if(l<=s && e<=r) return maxTree[node];

    int mid = (s+e)/2;
    return max( maxQuery(node*2,s,mid,l,r) , maxQuery(node*2+1,mid+1,e,l,r));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> M;

    arr.resize(N+1);
    minTree.resize(4*(N+1));
    maxTree.resize(4*(N+1));

    for(int i=1;i<=N;i++)cin>>arr[i];

    initMin(1,1,N);
    initMax(1,1,N);

    while(M--){
        int a,b;
        cin >> a >> b;
        cout << minQuery(1,1,N,a,b) << ' ';
        cout << maxQuery(1,1,N,a,b) << '\n';
    }
    return 0;
}