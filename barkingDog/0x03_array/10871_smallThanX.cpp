#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX = 10005;
int N,X,A[MAX];
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >>N >> X;
	
    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    for(int i=0;i<N;i++){
        if(A[i] < X){
            cout << A[i] << " ";
        }
    }

	return 0;
}