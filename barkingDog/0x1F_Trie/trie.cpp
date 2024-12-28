#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5;
bool chk[MX];
int nxt[MX][26];

int c2i(char c){
    return c - 'A';
}

void insert(string &s){
    int cur = ROOT;
    for(auto c:s){
        if(nxt)
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i=0;i<MX;i++){
        fill(nxt[i],nxt[i] + 26, -1);
    }


    return 0;
}