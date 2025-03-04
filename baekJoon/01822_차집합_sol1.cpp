#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int>A;
vector<int>B;
vector<int>ans;

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

    int i=0, j=0;

    while(i<a && j<b){
        if(A[i] == B[j]){
            i++,j++;
        }
        else if(A[i] < B[j]){
            ans.push_back(A[i]);
            i++;
        }
        else{
            j++;
        }
    }
    while(i<a){
        ans.push_back(A[i]);
        i++;
    }

    cout << ans.size() << '\n';
    for(int x:ans) cout << x << ' ';
    return 0;
}