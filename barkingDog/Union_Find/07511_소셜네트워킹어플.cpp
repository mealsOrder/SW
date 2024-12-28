#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>p(1000001,-1);

int Find(int x){
    if(p[x]<0) return x;
    return p[x] = Find(p[x]);
}

bool uni(int u,int v){
    u = Find(u);
    v = Find(v);

    if(u==v)return false;

    if(p[v] < p[u]){
        swap(u,v);
    }
    if(p[u] == p[v]){
        p[u]--;
    }
    p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    for(int tc=1;tc<=T;tc++){
        cout << "Scenario " << tc << ":\n";
        int N,K;
        cin >>N>>K;
        fill(p.begin()+1,p.begin()+N+1,-1);
        while(K--){
            int a,b;
            cin >> a >> b;
            uni(a,b);
        }
        int M;
        cin >> M;
        while(M--){
            int u,v;
            cin >> u >> v;
            cout << (Find(u) == Find(v)) << '\n';
        }
        cout << '\n';
    }
    return 0;
}