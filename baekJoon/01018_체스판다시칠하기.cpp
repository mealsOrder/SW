#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int MX = 51;
int N, M;
string map[MX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> map[i];

    int ans = BFS(0, 0);
    cout << ans << '\n';

    for (int i = 0; i < N; i++){
        cout << map[i]<<'\n';
    }
    return 0;
}