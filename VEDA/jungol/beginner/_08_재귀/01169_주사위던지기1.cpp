#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
const int MX = 10;
int N,M;
int arr[MX];
bool vis[MX];
set<vector<int>>s; // set 을 활용하여 벡터의 집합을 중복없이 저장

// 전체 경우의 수
void func1(int x){
    if(x == N){
        for(int i=0;i<N;i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=6;i++){
        arr[x]=i;
        func1(x+1);
    }
}

// 중복된 집합 제거 한 경우 
void func2(int x){
    if(x == N){
        vector<int> com(arr,arr+N); // 현재 조합을 벡터로 복사
        sort(com.begin(),com.end()); // 벡터를 정렬하여 중복 제거 준비
        
        // 정렬된 조합 com이 set 에 있는지 조사
        if(s.find(com) == s.end()){ // find 함수가 end()를 반환 한다는 것은 set 에 com 이 없다는 뜻
            s.insert(com);  // 중복이 아니면 set 에 집합 추가
            for(int i=0;i<N;i++){
                cout << arr[i] << " ";
            }
            cout << '\n';
        }
        return;
    }
    for(int i=1;i<=6;i++){
        arr[x]=i;
        func2(x+1);
    }
}

// 세 수가 서로 다른 경우
void func3(int x){
    if(x == N){
        for(int i=0;i<N;i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=6;i++){
        if(!vis[i]){
            arr[x]=i;
            vis[i] = true;
            func3(x+1);
            vis[i] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    //fill(arr,arr+MX,0);
    if(M == 1)func1(0);
    if(M == 2)func2(0);
    if(M == 3)func3(0);

    return 0;
}