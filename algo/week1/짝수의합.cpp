#include <iostream>

using namespace std;


const int MAX = 2001;

int main() {

    int N;
    int ans=0;
    cin >> N;

    for(int i=1;i<=N;i++){
        if(i%2 == 0) ans+=i;
    }

    cout << ans << endl;

    return 0; 
}