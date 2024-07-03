#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 51;
int N;
vector<int> graph[MX];

int DFS(int x){
    int ans = 0; // 현재 노드까지의 최대 시간을 저장
    vector<int>v; // 현재 노드의 자식 노드들에 대한 최대 시간 정보 저장

    // 현재 노드 x의 모든 자식 노드를 방문
    for(int i=0;i<graph[x].size();i++){
        int nx = graph[x][i];
        v.push_back(DFS(nx)); // 자식 노드에 대한 최대 시간 정보를 v에 저장
    }

    // v를 내림차순으로 정렬
    sort(v.begin(),v.end(),greater<int>());

    // 정렬된 v를 사용하여 현재 노드까지의 최대 시간 계산
    for(int i=0;i<v.size();i++){
        // 현재 노드 까지의 최대 시간 = 자식 노드의 최대 시간 + 자신의 순서
        ans = max(ans,v[i]+i+1); // +1 은 루트 노드
    }

    return ans; // 현재 노드까지의 최대 시간 반환
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    int root;
    cin >> root;
    for(int i=1;i<N;i++){
        int num;
        cin >> num;
        graph[num].push_back(i);
    }
    
    cout << DFS(0) << '\n';
    return 0;
}