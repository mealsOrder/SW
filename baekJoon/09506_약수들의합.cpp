        
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>

using namespace std;
const int MX = 100001;
vector<int>v(MX);
int main(){
    int sum;
    while(1){
        int n;
        v.clear();
        sum=0;
        cin >> n;
        if(n==-1)break;
        for(int i=1;i<n;i++){
            if(n%i == 0) {
                v.push_back(i);
                sum += i;
            }
        }
        if(sum == n){
            cout << n << " = ";
            for(int i=0;i<v.size()-1;i++) cout << v[i] << " + ";
            cout << v[v.size()-1];
        }
        else{
            cout << n <<" is NOT perfect.";
        }
        cout << '\n';
    }
	return 0;
}