#include <iostream>

using namespace std;

const int MAX = 2001;

void big(int x,int y){
        int temp = x;
        x=y;
        y = temp;
}
int ans;
int main() {

    int A,B,C;
    int temp;
    cin >>A>>B>>C;


    if(A>B){
        temp = A;
        A = B;
        B = A;
    }

    for(int i=A;i<=B;i++){
        if(i%C == 0) ans++;
    }

    cout << ans << endl;

    return 0; 
}