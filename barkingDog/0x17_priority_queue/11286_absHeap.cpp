#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

struct minAbs{
    // STL 컨테이너 원소를 절댓값이 작은 순서로 정렬하기 
    // 위해 operator() 함수를 오버로딩
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a>b;
        }
        return abs(a)>abs(b);
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >>N;

    vector<int>v(N);
    priority_queue<int,vector<int>,minAbs>pq;

    for(int i=0;i<N;i++){
        cin >> v[i];
        
        if(v[i] == 0){
            if(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            else{
                cout << "0\n";
            }
        }
        else{
            pq.push(v[i]);
        }
        
    }

    return  0;
}