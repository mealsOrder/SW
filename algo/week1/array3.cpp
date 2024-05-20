#include <iostream>

using namespace std;

const int MAX = 4;
int arr[MAX][MAX];

 
int main() {

    int N;

    cin >>N;
    int first=1;
    int num=1;
    int cnt = 0;

    
    for(int i=1;i<=N;i++){
        for(int j=N;j>=i;j--){
           num = num+cnt;
           cout << num << " ";
           cnt++;
        }
        first = first+i;
        num = first;

        cout << endl;
        cnt = i;
    }

    return 0;
}