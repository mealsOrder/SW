#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
const int MX = 51;
int arr[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    int fir = arr[0];
    sort(arr+1,arr+N);

    int cnt = 0;
    int lar = arr[N-1];
    while(true){
        if(N==1){
            cout << "0\n";
            return 0;
        }
        else if(fir > lar){
            cout << cnt << '\n';
            break;
        }
        else{
            fir++;
            lar--;
            cnt++;
            arr[N-1]=lar;
            sort(arr+1,arr+N);
            lar = arr[N-1];
        }
    }

    return 0;
}