#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){

    int T;
    cin >> T;
    int q=0;
    int d=0;
    int n=0;
    int p=0;
    for(int i=0;i<T;i++){
        int a;
        cin >> a;
        q = a/25;
        d = (a-(q*25))/10;
        n = (a-(q*25+d*10))/5;
        p = (a-(q*25+d*10+n*5))%10;

        cout << q << " "<< d << " "<< n << " "<< p << " ";
    }



	return 0;
}