#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
	
    int N,cnt;

    cin >>N;

    for(int i=2;i<=N;i++){

        if(N%i == 0){
            cnt++;
        }
    }

    if(cnt == 1){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
	

	return 0;
}