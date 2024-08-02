#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<climits>
using namespace std;
stack<pair<int,int>>s; // {현재높이,위치}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >>N;
    s.push({100000001,0});
    for(int i=1;i<=N;i++){
        int h;
        cin >> h;
        while(s.top().first < h) s.pop();
        cout << s.top().second << " ";
        s.push({h,i});
    }
    
    return 0;
}