#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

const int MX = 14;

int N;
int arr[MX];
int ans[MX];
bool vis[MX];
set<vector<int>>s; // set 활용하여 벡터의 집합을 중복없이 저장

void input(){
    for(int i=0;i<N;i++)cin>>arr[i];
}
void init(){
    fill(arr,arr+MX,0);
    fill(ans,ans+MX,0);
    fill(vis,vis+MX,0);
}
void back(int x){
    if(x == 6){
        vector<int>com(ans,ans+6);
        sort(com.begin(),com.end());

        // find 함수가 end()를 반환 한다는 것은
        // set에 com 이 없다는 뜻
        if(s.find(com) == s.end()){
            s.insert(com);
            for(int i=0;i<x;i++){
                cout << ans[i] << " ";
            }
            cout << '\n';
        }
        return;
    }
    else{
        for(int i=0;i<N;i++){
            if(!vis[i]){
                ans[x] = arr[i];
                vis[i] = true;
                back(x+1);
                vis[i] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    while(1){
        init();
        cin >> N;
        
        if(N == 0)  break;;
        input();
        back(0);
        cout << '\n';
    }

    return 0;
}