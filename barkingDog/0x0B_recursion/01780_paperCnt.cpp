#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
const int MX = 2200;
int arr[MX][MX];
int cnt[3]; // -1 0 1 

// x~x+n, y~y+n 가 같은지 확인 
bool check(int x,int y,int n){
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            // 하나라도 다르면 false
            if(arr[x][y] != arr[i][j]){
                return false;
            }
        }
    }

    return true;
}

// 분할 정복 하는 함수
void func(int x,int y,int z){
    // 9개 원소가 모두 같다면
    if(check(x,y,z)){
        // arr는 -1 0 1 중 하나 
        // +1 해준 이유 : idx값 맞추기 위해
        cnt[arr[x][y]+1] += 1;
        return;
    }
    int n = z/3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            func(x+i*n,y+j*n,n);
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
    for(int i=0;i<3;i++) cout << cnt[i] << '\n';
    return 0;
}