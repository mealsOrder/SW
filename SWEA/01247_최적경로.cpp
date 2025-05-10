#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

const int MX = 51;
vector<tuple<int,int,int>>t;
vector<int>p;
string arr[MX];
int N;

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
        int cost,from,to;
        tie(cost,from,to) = edge;

        if( Find(from) != Find(to)){
            Union(from,to);
            ans+=cost;
            connected++;
            if(connected == N-1) return ans;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    p.resize(N);
    for(int i=0;i<N;i++)p[i]=i;

    for(int i=0;i<N;i++)cin >> arr[i];
    
    int sum = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int len = 0;
            if( arr[i][j] >= 'a' && arr[i][j] <= 'z'){
                len = arr[i][j]-97 +1 ;
            } else if( arr[i][j] >= 'A' && arr[i][j] <= 'Z'){
                len = arr[i][j]-65 + 27 ;
            }
            sum+=len;

            if(i!=j && len!=0){
                t.push_back({len ,i,j });
            }
        }
    }
    int cc = kruskal();
    if(cc == -1) cout << -1 << '\n';
    else cout << sum - cc << '\n';
    
    return 0;
}