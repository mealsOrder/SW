#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//8 11 0 6
//0 1 3
//0 5 1
//1 2 4
//1 3 1
//1 5 1
//2 4 6
//2 6 9
//2 7 4
//3 4 2
//4 6 9
//6 7 3
 

const int INF = 987987987;
const int MAX = 101;

vector <int> v[MAX];
vector <int> cost[MAX];
int t[MAX];
bool check[MAX];
int N,M,S,E;

int main(){
	
	cin >> N>>M>>S>>E;
	
	for(int i=0;i<M;i++){
		int a,b,c;
		
		cin >> a >> b >> c;
		
		v[a].push_back(b);
		v[b].push_back(a);
		
		cost[a].push_back(c);
		cost[b].push_back(c);
	}
	
	for(int i=0;i<N;i++){
		t[i]=INF;
	}
	
	t[S] = 0;
	
	for(int i=0;i<N;i++){
		// (1)
		// (2)
		int minValue = INF;
		int minIdx = -1;
		
		for(int j=0;j<N;j++){
			if(!check[j] && minValue > t[j] ){
				minValue = t[j];
				minIdx = j;
			}
		}
		check[minIdx] = true;
		
		for(int j=0;j<v[minIdx].size();j++){
			int nextNode = v[minIdx][j];
			int nextCost = cost[minIdx][j];
			
			// minIdx ---(nextCost)--- nextNode
			
			if(t[nextNode] > t[minIdx] + nextCost){
				t[nextNode] = t[minIdx] + nextCost;
			}
			
		}
	}

	cout << t[E] << endl;
	
	return 0;
}