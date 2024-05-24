#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>A;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        A.push_back(a);
    }

    sort(A.begin(),A.end());

    cin >> M;
    for(int i=0;i<M;i++){
        int b;
        cin >> b;

        // upper_bound : b 보다 큰값이 처음 나오는 위치(이레이터)
        // lower_bound : b 보다 작거나 같은 값이 처음 나오는 위치(이레이터) 
        int res = (upper_bound(A.begin(),A.end(),b)-lower_bound(A.begin(),A.end(),b));
        cout << res << " ";
    }

    return 0;
}