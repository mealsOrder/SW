#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int>v;

int main(){
	
    int N,K,cnt=0;
    bool flag = false;
    cin >>N>>K;

    for(int i=1;i<=N;i++){
        if(N%i == 0){
            cnt++;
        }


        if(cnt == K){
            flag = true;
            cout << i << endl;
            break;
        }

    }

    if(!flag) cout << "0\n";

	return 0;
}