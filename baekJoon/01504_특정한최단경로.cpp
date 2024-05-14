#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

const int MAX = 805;
const int INF = INT_MAX;

vector<pair<int,int>>v[MAX];

int dist[MAX];
int N,E;
int sToV1, sToV2, V1ToV2, V1ToN, V2ToN;

priority_queue< pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>>q;

void dijk(int start){
	fill(dist,dist+MAX,INF);
	dist[start] = 0;
	q.push({0,start}); // curDist, curNode
	
	while(!q.empty()){
		int curDist = q.top().first;
		int cur = q.top().second;
		q.pop();
		
		for(int i=0;i<v[cur].size();i++){
			int next = v[cur][i].first;
			int nDist = v[cur][i].second;
			
			if(dist[next] > curDist + nDist ){
				dist[next] = curDist + nDist;
				q.push({dist[next],next });
			}
			
		}
		
	}

}

int main(){
	
	
	
	cin >> N>>E;
	
	for(int i=0;i<E;i++){
		int a,b,c;
		
		cin >> a>>b>>c;
		
		v[a].push_back({b,c});
		v[b].push_back({a,c});
		
	}
	
	int v1,v2;
	
	cin >> v1 >> v2;
	
	dijk(1);
	sToV1 = dist[v1];
	sToV2 = dist[v2];
	
	dijk(v1);
	V1ToV2 = dist[v2];
	V1ToN = dist[N];
	
	dijk(v2);
	V2ToN = dist[N];
	
	int ans1 = sToV1 + V1ToV2 + V2ToN;
	int ans2 = sToV2 + V1ToV2 + V1ToN;
	
	int ans = min(ans1,ans2);
	
	if(ans >=INF){
		cout << "-1" <<endl;
	}
	else{
		cout << ans << endl;
	}
	
	return 0;
}
