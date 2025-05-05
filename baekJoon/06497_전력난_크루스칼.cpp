#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int M,N,ans;
vector<int>p;
vector<tuple<int,int,int>>t;

int Find(int x){
    if(x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Union(int x,int y){
    x = Find(x);
    y = Find(y);

    if(y>x) p[y]=x;
    else p[x] = y;
}

int kruskal(){
    sort(t.begin(),t.end());
    int connected=0;
    int ans = 0;
    

    for(auto& edge:t){
        int cost,from,to;
        tie(cost,from,to)=edge;

        if(Find(from) != Find(to)){
            Union(from,to);
            connected++;
            ans+=cost;

            if(connected == M-1){
                return ans;
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(true){
        cin >> M >> N;

        if(M == 0 && N == 0)break;

        p.resize(M+1);

        for(int i=0;i<M;i++)p[i]=i;
        t.clear();  // 매 테스트 케이스 마다 튜플 초기화 시켜줘야 오답 안남
        int sum = 0;
        for(int i=0;i<N;i++){
            int a,b,c;
            cin >> a >> b >> c;

            sum+=c;
            t.push_back({c,a,b});
        }
        int mi = kruskal();
        cout << sum - mi << '\n';
    }

    return 0;
}