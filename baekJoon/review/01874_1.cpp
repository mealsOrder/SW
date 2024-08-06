#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
const int MX = 100001;

char res[MX*2];
int stack_arr[MX];
int top=-1;
int arr[MX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N,res_idx=0;
    stack<int>s;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=N;i++){
        if( s.top()==-1 ||  s.top()<arr[i]){
            s.push(i);
            res[res_idx++]='+';
        }
        else if(s.top() == arr[i]){
            s.pop();
            res[res_idx++]='-';
        }
        else{
            cout << "NO\n";
            return 0;
        }
        if(res_idx == N*2)break;
    }
    for(int i=0;i<res_idx;i++){
        cout << res[i] << '\n';
    }
    return 0;
}