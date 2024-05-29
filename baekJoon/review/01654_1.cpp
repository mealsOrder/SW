#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
const int MX = 10001;
long long arr[MX];    

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long K,N;
    cin >>K>>N;
    for(int i=0;i<K;i++){
        cin >> arr[i];
    }
    sort(arr,arr+K);

    long long lef = 1;
    long long rig = arr[K-1];
    long int ans = 0;
    while(lef<=rig){
        long long sum=0;
        long long mid = (lef+rig)/2;

        for(int i=0;i<K;i++){
            sum+= arr[i]/mid;
        }

        if(sum < N){
            rig = mid - 1;
        }
        else{
            ans = mid;
            lef = mid + 1;
        }
    }

    cout << ans;

    return 0;
}