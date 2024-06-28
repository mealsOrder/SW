#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // 문자열이 들어올지 숫자가 들어올지 모르니 일단 string으로 입력받음
    string a,b,c;
    cin >> a>>b>>c;
    int ans;
    // 연속된 3개의 수라고 생각하고
    // 입력된 문자열이 숫자면 정답은 순서대로 +3,+2,+1 이 된다.
    // 3개 문자열 다음에 올 값을 구하기 때문에
    if(a[0] != 'F' && a[0] != 'B') ans = stoi(a)+3;
    else if(b[0] != 'F' && b[0] != 'B') ans = stoi(b)+2;
    else if(c[0] != 'F' && c[0] != 'B') ans = stoi(c)+1;

    // 구한 정답이 3의 배수이면서 5의 배수이면
    if(ans % 15 == 0)cout << "FizzBuzz";
    // 5의 배수이면 Buzz
    else if(ans % 5 == 0)cout << "Buzz";
    // 3의 배수이면 Fizz
    else if(ans % 3 == 0)cout << "Fizz";
    // 위 조건에 해당하지 않으면 그냥 정답을 출력한다.
    else cout << ans;
    
    return 0;
}