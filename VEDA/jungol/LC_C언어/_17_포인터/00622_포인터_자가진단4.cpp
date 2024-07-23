#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[5];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<5;i++)cin>>a[i];
    
    int *pa = a;

    for(int i=0;i<5;i++){
        if(i%2 == 0){
            cout << *(pa+i) << " ";
        }
    }

    return 0;
}