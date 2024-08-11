#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int func(vector<int>&a){
    int sum = 0;
    for(int elem:a){
        if(sum+1 < elem){
            return sum+1;
        }
        sum+=elem;
    }
    return sum+1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int>v;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    cout << func(v);
    return 0;
}