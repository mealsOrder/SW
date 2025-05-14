#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int MX =1000001;
int A[MX];
int B[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    int idx = 0;
    B[0] = A[0];

    for(int i=1;i<N;i++){
        if(A[i] > B[idx]){
            B[++idx] = A[i];
        }
        else{
            int loc = lower_bound(B,B+idx+1,A[i])-B;
            B[loc] = A[i];
        }
    }
    cout << idx+1 << '\n';
	return 0;
}