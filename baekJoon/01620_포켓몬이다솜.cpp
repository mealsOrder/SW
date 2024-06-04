#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int N, M; 
    cin >> N >> M; 
    map<string, int> name_to_num;   // 포켓몬 이름을 키로, 번호를 값으로 하는 맵
    string num_to_name[N+1];        // 포켓몬 번호를 인덱스로, 이름을 값으로 하는 배열
    for(int i=1; i<=N; i++){ 
        string name;                
        cin >> name;               
        name_to_num[name] = i;      // 맵에 포켓몬 이름과 번호를 저장
        num_to_name[i] = name;      // 배열에 포켓몬 번호와 이름을 저장
    }
    for(int i=0; i<M; i++){ 
        string qes; 
        cin >> qes; 

        // isdigit >> 문자열에서 숫자를 판단하는 함수
        // 해당 문자가 숫자이면 0이 아닌 수를 반환
        // 문자가 들어오면 0을 반환!
        if(isdigit(qes[0])){      // 문제가 숫자로 주어졌으면
            int num = stoi(qes);  // 문자열을 정수로 변환
            cout << num_to_name[num] << '\n'; // 해당 번호의 포켓몬 이름을 출력
        } 
        // 문제가 이름으로 주어졌으면
        else { 
            cout << name_to_num[qes] << '\n'; // 해당 이름의 포켓몬 번호를 출력
        }
    }
    return 0;
}
