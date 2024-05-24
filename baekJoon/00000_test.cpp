#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 500001
using namespace std;
vector<int>A;
vector<int>B;
vector<int>ans;
int cnt;
int main(){
    int N,M;
    cin >> N;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        A.push_back(a);
    }


    cin >> M;
    for(int i=0;i<M;i++){
        int b;
        cin >> b;
        B.push_back(b);
    }

    sort(A.begin(),A.end());

    for(int num:B){
        int res = (upper_bound(A.begin(),A.end(),num)-lower_bound(A.begin(),A.end(),num));
        ans.push_back(res);
    }

    for(int elem:ans){
        cout << elem << " ";
    }

    return 0;
}