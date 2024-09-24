#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 100001;
int G,P,cnt;
bool flag = true;
bool visited[MX];
int arr[MX];

int solved(int gate){
    if(arr[gate] == gate) return gate;
    return arr[gate] = solved(arr[gate]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> G >> P;

    for(int i=1;i<=G;i++) arr[i] = i;

    for(int i=0;i<P;i++){
        int a;
        cin >> a;

        if(flag){
            int root = solved(a);
            if(visited[root]){
                flag = false;
                continue;
            }
            visited[root] = true;
            arr[root] = solved(max(1,root-1));
            cnt++;
        }
    }

    cout << cnt << '\n';

	return 0;
}