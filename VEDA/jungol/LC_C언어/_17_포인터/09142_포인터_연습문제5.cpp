#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[3],b[3];
char atr[20],btr[20];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<3;i++){
        cin >>a[i];
    }
    for(int i=0;i<3;i++){
        cin >>b[i];
    }
    for(int i=0;i<5;i++){
        cin >> atr[i];
    }
    for(int i=0;i<5;i++){
        cin >> btr[i];
    }
    int *pa = a;
    int *pb = b;
    char *pat = atr;
    char *pbt = btr;
    for(int i=0;i<3;i++){
        cout << pa[i] << " ";
    }
    cout << '\n';
    for(int i=0;i<3;i++){
        cout << *(pb+i) << " ";
    }
    cout << '\n';
    for(int i=0;i<5;i++){
        cout << atr[i];
    }
    cout << '\n';
    for(int i=0;i<5;i++){
        cout << *(pbt+i);
    }
    return 0;
}