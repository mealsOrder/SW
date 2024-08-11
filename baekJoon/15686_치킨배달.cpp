#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 51;
const int INF = INT_MAX;
int N,M;
int map[MX][MX];
int dist[MX][MX];
int ans = INF;
vector<pair<int,int>>house;
vector<pair<int,int>>chicken;
vector<pair<int,int>>temp;

int cal(int a,int b,int c, int d){
    return abs(a-c) + abs(b-d);
}
int findPath(){
    int res = 0;
    for(int i=0;i<house.size();i++){
        int dis1 = INF;
        for(int j=0;j<temp.size();j++){
            int dis2 = abs(house[i].first - temp[j].first) + abs(house[i].second-temp[j].second);
            dis1 = min(dis1,dis2);
        }
        res+=dis1;
    }
    return res;
}
void func(int x,int cur){
    if(x == M){
        for(int i=0;i<M;i++){
            ans = min(ans,findPath());
        }
        return;
    }
    else{
        for(int i=cur;i<chicken.size();i++){
            int x = chicken[i].first;
            int y = chicken[i].second;
            temp.push_back({x,y});
            func(x+1,i+1);
            temp.pop_back(); 
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];

            if(map[i][j] == 1){
                house.push_back({i,j});
            }
            else if(map[i][j] == 2){
                chicken.push_back({i,j});
            }
        }
    }

    func(0,0);
    cout << ans << '\n';
    return 0;
}