#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 11;

int a[MAX];
int b[MAX];

int main() {
    int A=0,B=0;
    for(int i=0;i<10;i++){
        cin >> a[i];
    }
    for(int i=0;i<10;i++){
        cin >> b[i];
    }

    
    for(int i=0;i<10;i++){
        if(a[i] == b[i]) {
            continue;
        }
        else if(a[i]>b[i]){
            A++;
        }
        else{
            B++;
        }

    }

    if(A==B){
        cout << "D\n";
    }
    else if(A>B){
        cout << "A\n";
    }
    else{
        cout << "B\n";
    }

    return 0; 
}