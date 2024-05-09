#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 10001;
const int INF = INT_MAX;

int dist[MAX];
bool visited[MAX];
vector <int> v[MAX];

int N,M;

void dijkstra(int start){
	fill(dist,dist+MAX,INF);
	dist[start]=0;
	
	for(int i=0;i<N;i++){
		int minValue = INF;
		int minIdx = -1;
		
		
		for(int j=0;j<N;j++){
			if(!visited[j] && dist[j] < minValue){
				minValue = dist[j];
				minIdx = j;
			}
		}
		
		if(minIdx == -1) break;
		
		visited[minIdx] = true;
		
		// j: link
		for(int j=0;j<v[minIdx].size();j++){
			int next = v[minIdx][j];
			int nDist = dist[minIdx]+1;
			
			if(dist[next] > nDist){
				dist[next] = nDist;				
			}
			
		}
		
	}	
	
}

int main() {
    
    cin >> N >> M;
    
    for(int i=0;i<M;i++){
    	int a,b;
    	cin >> a >> b;
    	
    	v[a].push_back(b);
    	v[b].push_back(a);
    	
	}
    
    int S,E;
    cin >> S >> E;
    dijkstra(S);
	
	cout << dist[E] << endl;
	
    return 0;
}