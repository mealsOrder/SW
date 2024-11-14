#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 5001;
struct Bus{
    int no;
    int xs,xe;
    int ys,ye;
};
Bus bus[MX];
int vis[MX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M,N,K;
    cin >> M >> N >> K;

    for(int i=0;i<K;i++){
        int b,x1,y1,x2,y2;
        cin >> b >> x1 >> y1 >> x2 >> y2;
        bus[i] = {b,min(x1,x2),}
    }
    
    return  0;
}