#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>A;
vector<int>B;

int main() {
    
    int T;

    cin >> T;

    while(T--){
        int N,M;
        int ans=0;
        cin >>N>>M;
        for(int i=0;i<N;i++){
            int a;
            cin >> a;
            A.push_back(a);

        }
        for(int i=0;i<M;i++){
            int b;
            cin>>b;
            B.push_back(b);
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        for(int num:A){
            
            int left=0;
            int right = M-1;
            
            while(left<=right){
                int mid = (left+right)/2;

                if(num > B[mid]) left = mid+1;
                else if(num <= B[mid]) right = mid-1;
            }
            ans += left;
        }

        cout << ans << '\n';
        A.clear();
        B.clear();
    }

    return 0;
}