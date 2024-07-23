#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

const int MX = 101;
int arr[MX][MX];
int N,x,y,dir,val;
int dx[] = {1,-1};
int dy[] = {-1,1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    x = y = 1;

    for(int i=1;i<=N;i++){
        arr[x][y] = ++val;
        for(int j=1;j<i;j++){
            x = x+dx[dir];
            y = y+dy[dir];
            arr[x][y] = ++val;
        }

        if(i%2 == 0){
            if(i == N) x++;
            else y++;
            dir=0;
        }
        else{
            if(i==N)y++;
            else x++;
            dir=1;
        }
    }
    
    for(int i=N-1;i>=1;i--){
        arr[x][y] = ++val;
        for(int j=1;j<i;j++){
            x = x+dx[dir];
            y = y+dy[dir];
            arr[x][y] = ++val;
        }

        if(i%2 == 0){
            x++;
            dir=0;
        }
        else{
            y++;
            dir=1;
        }
    }


    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}