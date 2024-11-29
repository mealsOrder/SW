#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int MX = 202;
const int INF = 987987987;
int N,M,K;

int c[MX];
int d[MX][MX];

void func(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                d[i][j] = min(d[i][k]+d[k][j],d[i][j]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> M;

    for(int i=1;i<=N;i++){
        fill(d[i],d[i]+N+1,INF);
        d[i][i] = 0;
    }

    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b],c);
    }

    cin >> K;

    for(int i=1;i<=K;i++){
        int a;
        cin >> a;
        c[i] = a;
    }

    func();

    vector<pair<int,int>>v;
    for(int i=1;i<=N;i++){
        int mx = 0;
        for(int j=1;j<=K;j++){
            mx = max(mx,d[i][c[j]] +d[c[j]][i]);
        }
        v.push_back({mx,i});
    }
    sort(v.begin(),v.end());

    int mn = v[0].first;
    for(auto cur : v){
        if(mn < cur.first)break;
        cout << cur.second << " ";
    }
    return 0;
}
