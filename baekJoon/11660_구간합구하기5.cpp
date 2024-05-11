#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MAX = 1026;

int map[MAX][MAX];


int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int N,M;
	
	cin >> N >> M;
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			int a;
			cin >> a;
			map[i][j] = map[i-1][j] + map[i][j-1]+ a - map[i-1][j-1];
		}
	}
    
	
	
	for(int i=0;i<M;i++){
		int x,y,nx,ny;
		int ans=0;
		cin >> x >> y >> nx >> ny;
		ans = map[nx][ny] - map[x-1][ny] - map[nx][y-1] + map[x-1][y-1];
		cout << ans << '\n';
	}
	
	

	return 0;
}