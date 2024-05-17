#include<iostream>
#include<set>
#include<string>
#include<cstring>

using namespace std;

/*
set은 중복없이 저장하는 자료구조이다. 집합이라고 생각하면 된다!
*/

// set은 템플릿 클래스이기 때문에 set객체를 선언할 때에는
// set에 들어갈 원소들의 타입을 적어줘야 한다.

set<int>a;
set<int>s;
set<string>c;

int main(){
    
    // 원소 집어넣기
    a.insert(3);

    int arr[10] = {1,1,2,3,4,4,5,5,6,7};
    // 1,4,5 각각 2개씩 중복되어 있는 배열을 set에 넣자

    for(int i=0;i<10;i++){
        s.insert(arr[i]);

    }

    cout << "set s의 크기: " << s.size() << endl;

    // 삭제
    s.erase(1);

    // set 객체가 비어있는지 확인하려면 
    // s.empty() size 0 이면 비어있는것
    // s.empty()는 비어있으면 1 아니면 0 리턴
    cout << s.empty() << " ";  
    for(set<int>::iterator i=s.begin();i!=s.end();i++){
        cout << *i << " ";
    }
    cout << endl;
    

    return 0;
}