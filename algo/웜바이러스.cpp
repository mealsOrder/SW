#include <iostream>
#include <vector>

using namespace std;


const int MAX = 200;



int N,M;
vector<int>v[MAX];
int visited[MAX];
int cnt;

void DFS(int x){
  visited[x] = true;
  cnt++;
  //cout << x << " ";
  for(int i=0;i<v[x].size();i++){
    int y = v[x][i];
    
    if(visited[y] == false){
      DFS(y);
      
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
  
  DFS(1);
  
  cout << cnt-1;
  
  return 0;
}