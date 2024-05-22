#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int MAX = 1001;

int map[MAX][MAX];
int cnt[MAX];
int main() {
    
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        int a,b,r,h;

        cin >> a>>b>>r>>h;
        for(int j=a;j<a+r;j++){
            for(int k=b;k<b+h;k++){
                map[j][k] = i;
            }
        }
    }

    for(int i=0;i<MAX;i++ ){

        for(int j=0;j<MAX;j++ ){
            
            cnt[map[i][j]]++;
            
        }
    }


    for(int i=1;i<=N;i++){
        cout << cnt[i] <<'\n';
    }

    return 0;
}