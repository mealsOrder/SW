#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MX = 101;
int N;
int arr[MX][MX];
void func(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(arr[i][k] && arr[k][j]){
                    arr[i][j] =1;
                }
            }
        }
    }
}
int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    func();
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << arr[i][j]<< " ";
        }
        cout << '\n';
    }
    return 0;
}