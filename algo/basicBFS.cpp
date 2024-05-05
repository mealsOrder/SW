#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 100;

vector<int>v[MAX];
bool check[MAX];
queue <int> q;

int N,M;


//// input
//9 12
//1 2
//1 3
//2 3
//2 4
//2 6
//3 7
//4 5
//4 7
//4 8
//5 6
//7 8
//8 9
//
//// out
//1 2 3 4 6 7 5 8 9

void BFS(){
  
  q.push(1);
  check[1] = true;
  
  while(!q.empty()){
    int current = q.front();
    q.pop();
    cout << current << " ";
    
    for(int i=0;i<v[current].size();i++){
      int next = v[current][i];
      
      if(check[next] == false){
        check[next] = true;
        q.push(next);
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
  
  BFS();
  
    
  return 0;
}