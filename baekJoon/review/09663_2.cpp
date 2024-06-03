#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MX = 101;
int N;
int cnt;
bool v1[MX];
bool v2[MX];
bool v3[MX];
void back(int x){
    if(x==N){
        cnt++;
        return;
    }
    for(int i=0;i<N;i++){
        if(v1[i]||v2[x+i]||v3[x-i+N-1])continue;

        v1[i]=1;
        v2[i+x]=1;
        v3[x-i+N-1]=1;
        back(x+1);
        v1[i]=0;
        v2[i+x]=0;
        v3[x-i+N-1]=0;
        
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >>N;
    back(0);
    cout << cnt<<'\n';


    return 0;
}