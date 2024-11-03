#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int MX = 9;

int arr[MX][MX];
int zCnt;
int main(){
	ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
            cin >> arr[i][j];
            if(arr[i][j])zCnt++;
        }
    }
	return 0;
}