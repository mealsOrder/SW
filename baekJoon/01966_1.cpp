#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
const int MX = 101;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int T; 
    cin >> T;
    while(T--){ 
        int N,M; 
        cin >> N >>M;
        vector<int>v(N); 
        queue<pair<int,int>>q; 
        for(int i=0;i<N;i++){
            cin >> v[i]; 
            q.push({v[i], i}); 
        }
        sort(v.begin(),v.end(),greater<>()); 
        int cnt =0, idx = 0; 
        while(!q.empty()){
            int prime = q.front().first; 
            int loc = q.front().second; 
            q.pop();

            if(prime == v[idx] ){ 
                cnt++; 
                idx++; 
                if(loc == M){ 
                    cout << cnt << '\n'; 
                    break;
                }
            }else{ 
                q.push({prime,loc}); // 문서를 큐의 맨 뒤로 이동
            }
        }

    }

	return 0;
}
