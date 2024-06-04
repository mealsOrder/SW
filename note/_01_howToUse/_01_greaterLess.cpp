#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

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

    priority_queue<int,vector<int>,greater<>>pq;
    priority_queue<int,vector<int>,greater<int>>rq;
    /**
     * greater<>는 함수 객체로, 
     * 두 인수를 비교하고 첫 번째 인수가 두 번째 인수보다 큰 경우 
     * true를 반환합니다. 여기서 greater<>는 템플릿 
     * 인수를 자동으로 추론하므로, 우선순위 큐의 요소 유형에 따라 
     * 자동으로 조정됩니다
     * 반면 greater<int>는 역할과 구동은 동일하고 다만 
     * 명시적으로 int 유형의 인수를 비교하는 함수 객체입니다.
     * 
     * 차이점은 주로 코드의 가독성과 유지 관리성에 영향을 미칩니다. 
     * greater<>를 사용하면 우선순위 큐의 요소 유형이 변경되더라도 
     * 비교 함수를 변경할 필요가 없으므로, 코드의 유연성이 향상됩니다. 
     * 반면에 greater<int>를 사용하면, 우선순위 큐의 요소 유형이 
     * int에서 다른 유형으로 변경되는 경우, 비교 함수도 명시적으로 
     * 변경해야 합니다. 이는 추가적인 유지 관리 작업을 필요로 합니다.
    */
    




    return 0;
}