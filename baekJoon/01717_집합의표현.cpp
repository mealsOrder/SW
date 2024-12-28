#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 1000001;

int N,M;
int root[MX];   // 부모를 담는 배열
int nRank[MX];  // 트리의 높이 담는 배열

int find(int x){
    if(root[x] == x){
        return x;
    }
    else{
        return root[x] = find(root[x]);
    }
}

// 합치기
void unions(int x, int y){
    x = find(x);
    y = find(y);

    // 두 값의 root가 같으면(이미 같은 트리)이므로 합치지 않는다
    if(x == y) return ;

    // 항상 높이가 더 높은 트리를 root 쪽으로 넣는다
    if(nRank[x] < nRank[y]){
        root[x] = y;
    }
    else{
        root[y] = x;
        // 만약 높이가 같다면 합친 후 x의 높이 +1
        if(nRank[x] == nRank[y]){
            nRank[x]++;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i=0;i<MX;i++){
        root[i] = i;
        nRank[i] = 0; // 트리 높이 초기화
    }

    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        // 두 원소가 같은 집합에 포함되어 있는가?
        if(a){
            // 루드 노드가 같으면 같은 집합에 포함
            if(find(b) == find(c)) cout << "YES\n";
            else cout << "NO\n";
        }
        // 그렇지 않으면 두 트리를 합치기
        else{
            unions(b,c);
        }
    }

    return 0;
}