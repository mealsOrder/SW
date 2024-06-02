#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// 내가 정의한 compare 함수
bool comPare(int a,int b){
    return a>b;
}
vector<int>v;
int main(){
    // 함수 생략하고 정렬 >> 오름차순 정렬    
    v = {7, 5, 1, 3, 9, 4 };
    sort(v.begin(),v.end());
    cout << "No compare function : " ;
    for(auto num:v)cout << num << " ";
    cout << '\n';
    
    // return a>b; 함수로 정렬 >> 내림차순 정렬
    v = {7, 5, 1, 3, 9, 4 };
    sort(v.begin(),v.end(),comPare);
    cout << "return a>b compare function : " ;
    for(auto num:v)cout << num << " ";
    cout << '\n';

    // greater<>() 사용 >> 내림차순 정렬
    v = {7, 5, 1, 3, 9, 4 };
    sort(v.begin(),v.end(),greater<>());
    cout << "greater function : " ;
    for(auto num:v)cout << num << " ";
    cout << '\n';

    // less<>() 사용 >> 오름차순 정렬
    v = {7, 5, 1, 3, 9, 4 };
    sort(v.begin(),v.end(),less<>());
    cout << "less function : " ;
    for(auto num:v)cout << num << " ";
    cout << '\n';





    return 0;
}