#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<cstring>
using namespace std;

const int MAX = 1000001;
vector<int>v;
vector<int>r;

/*
// 시작부터 끝까지 중복된 아이들을 뒤로 보내는데
// unique는 중복된 아이들의 첫번째 주소를 반환함
unique(v.begin(),v.end())

// a~b까지 지워버림
erase(a,b)

// 사용 조건 : 정렬되어 있어야함!
lower_bound : 찾으려는 key값보다 같거나 큰 숫자가 
배열 몇번째에서 처음 등장하는 위치를 반복자로 리턴

upper_bound : 찾으려는 key값보다 작거나 같은 숫자가 
배열 몇번째에서 처음 등장하는 위치를 반복자로 리턴
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        v.push_back(a);
        r.push_back(a);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end() );
    for(int i=0;i<N;i++){
        // lower_bound() 함수가 반환하는 반복자에서 v.begin()을 빼면, 
        // 입력된 값이 배열에서 몇 번째 위치에 있는지를 알 수 있다.
        cout << lower_bound(v.begin(),v.end(),r[i]) - v.begin() << " ";
    }
    return 0;
}