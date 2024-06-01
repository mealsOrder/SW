#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MX = 2200;
int arr[MX][MX];
int N;
int cnt[3];
bool check(int x,int y,int n){

    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(arr[x][y] != arr[i][j]){
                return false;
            }
        }
    }

    return true;
}

void func(int x,int y,int z){
    int tHalf = z/3;

    if(check(x,y,z)){
        cnt[arr[x][y]+1]+=1;
        return;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            func(x+tHalf*i,y+tHalf*j,tHalf);
        }
    }
}
int main(){
    cin >>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    func(0,0,N);
    for(int i=0;i<3;i++)cout << cnt[i]<<'\n';
    return 0;
}