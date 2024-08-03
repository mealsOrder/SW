#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,sum=0;
    cin >> N;
    stack<int>s;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        if(a == 0){
            s.pop();
        }
        else s.push(a);
    }

    while(!s.empty()){
        sum+=s.top();
        s.pop();
    }
    cout << sum << '\n';
	return 0;
}