#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
const int MAX = 26;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        string a;
        string b;
        int s[MAX] ={};

        bool flag=true;
        cin >> a >> b;
        for(auto k:a) s[k-'a']++;
        for(auto k:b) s[k-'a']--;
        
        for(int d:s){
            //cout << d << " ";
            if(d !=0 ) flag = false;
        }
        if(flag) cout << "Possible\n";
        else cout << "Impossible\n";
    } 
    return 0;
}