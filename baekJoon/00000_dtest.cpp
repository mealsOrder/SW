#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int>A;
vector<int>B;
vector<int>ans;
int cnt;
int lef,rig,mid;
bool bin(int tar, vector<int>b){
    lef = 0;
    //cout << lef << " ";
    rig = b.size()-1;
    //cout << rig << " ";
    mid = (lef+rig)/2;
    
    while(lef <= rig){
        //if(b[lef] == tar || b[rig] == tar) return 1;
        mid = (lef+rig)/2;
        
        if(b[mid] == tar){
            return 1;
        }else if(b[mid] < tar){
            lef = mid +1;
        }else if(b[mid] >tar){
            rig = mid -1;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b;
    cin >> a >> b;

    for(int i=0;i<a;i++){
        int n;
        cin >> n;
        A.push_back(n);
    }
    for(int i=0;i<b;i++){
        int n;
        cin >> n;
        B.push_back(n);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    for(int i=0;i<A.size();i++){
        if( bin(A[i],B) == 0){
            ans.push_back(A[i]);
        }
        //cout << bin(A[i],B) << '\n';
    }
    cout << ans.size() <<'\n';
    for(int x:ans) cout << x << ' ';
    return 0;
}