#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MX = 130;
int arr[MX][MX];
int cnt[2];// 0 1

bool check(int x,int y, int n){

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
    int half = z/2;
    if(check(x,y,z) && arr[x][y]==0){
        cnt[0]+=1;
        return;
    }
    
    if(check(x,y,z) && arr[x][y]==1){
        cnt[1]+=1;
        return;
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            func(x+i*half,y+j*half,half);
        }
    }
}

int main(){
    int N;

    cin >>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    func(0,0,N);
    for(int i=0;i<2;i++)cout << cnt[i] << '\n';
    return 0;
}