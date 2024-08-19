#include<iostream>
#include<algorithm>
using namespace std;
const int MX = 1026;
int arr[MX][MX];

int pol(int x,int y,int len){
    if(len == 1) return arr[x][y];
    len /=2;
    int ans[4];
    ans[0] = pol(x,y,len);
    ans[1] = pol(x+len,y,len);
    ans[2] = pol(x,y+len,len);
    ans[3] = pol(x+len,y+len,len);
    sort(ans,ans+4);
    return ans[2];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    cout << pol(0,0,N);
    return 0;
}