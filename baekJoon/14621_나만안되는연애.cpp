#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

const int MX = 1001;
vector<int>p;
vector<tuple<int,int,int>>t;

int N,M;
string str[MX];
int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int x,int y){
    x = Find(x);
    y = Find(y);

    if(y>x) p[y] = x;
    else p[x] = y;
}

int kruskal(){
    sort(t.begin(),t.end());
    int connected = 0;
    int ans = 0;
    for(auto edge:t){
        int cost = get<0>(edge);
        int from = get<1>(edge);
        int to = get<2>(edge);

        if(Find(from) != Find(to)){
            Union(from,to);
            ans+=cost;
            connected++;

            if(connected == N-1){
                return ans;
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=1;i<=N;i++){
        cin >> str[i];
    }

    p.resize(N+1);
    for(int i=1;i<=N;i++)p[i] = i;
    

    for(int i=1;i<=M;i++){
        int a,b,c;
        cin >> a >> b>> c;
        if(str[a] != str[b]){
            t.push_back({c,a,b});
        }
    }

    cout << kruskal();

    
    return 0;
}