#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N,M;
    cin >> N>>M;
    vector<int>A;
    vector<int>B;
    vector<int>uni;
    vector<int>inter;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0;i<M;i++){
        int b;
        cin >> b;
        B.push_back(b);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    set_union(A.begin(),A.end(),B.begin(),B.end(),back_inserter(uni));
    set_intersection(A.begin(),A.end(),B.begin(),B.end(),back_inserter(inter));

    cout << uni.size() - inter.size()<< '\n'; 

    return 0;
}