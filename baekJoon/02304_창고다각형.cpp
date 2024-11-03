#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MX = 1001;
int arr[MX];
int maxN;
int minN = 999999;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        arr[a] = b;
        maxN = max(maxN,a);
        minN = min(minN,a); 
    }

    for(int i = minN;i<=maxN;i++){
        for(int j=i;)
    }

    return 0;
}