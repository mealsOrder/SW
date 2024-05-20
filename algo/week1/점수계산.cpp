#include <iostream>

using namespace std;
const int MAX =101;
int arr[MAX];
int ans[MAX];
int main() {
    int N;
    int cnt = 0;
    cin >>N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    for(int i=0;i<N;i++){
        if(arr[i] == 1){
            cnt++;
            
        }else{
            cnt = 0;

        }
        ans[i] = cnt;
    }
    int sum=0;
    for(int i=0;i<N;i++){
        sum+=ans[i];
    }
    cout << sum << endl;
    return 0;
}