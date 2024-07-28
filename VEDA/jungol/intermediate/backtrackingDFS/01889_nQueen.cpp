#include<iostream>
#include<algorithm>
using namespace std;
const int MX = 40;
int N;
int cnt;
bool vis1[MX];
bool vis2[MX];
bool vis3[MX];
void func(int x){
    if(x == N){
        cnt++;
        return;
    }
    for(int i=0;i<N;i++){
        if(vis1[i] || vis2[x+i] || vis3[x-i+N-1])continue;
        vis1[i] = true;
        vis2[x+i] = true;
        vis3[x-i+N-1] = true;
        func(x+1);
        vis1[i] = false;
        vis2[x+i] = false;
        vis3[x-i+N-1] = false;
    }
}
int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> N;

    func(0);

    cout << cnt << '\n';

	return 0;
}