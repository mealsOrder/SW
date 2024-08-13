#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

void func(int n, int from, int temp, int to){
    if(n==1){
        cout << from << " " << to << '\n';
        return;
    }

    func(n-1,from,to,temp);
    cout << from << " " << to << '\n';
    func(n-1,temp,from,to);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    
    string num = to_string(pow(2,N));
    string ans="";

    for(int i=0;i<num.length();i++){
        if(num[i]=='.')break;
        else ans+=num[i];
    }
    ans[ans.length() - 1] -= 1;

	cout << ans << '\n';
    if(N<=20)func(N,1,2,3);
    
    
    return 0;
}