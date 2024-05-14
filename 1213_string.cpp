#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;


int main(){
    // 10개의 테스트 케이스에 대해 반복
    for(int t=1;t<=10;t++){
        string line,ob; // 문장과 찾을 문자열을 저장할 변수
        int ans = 0; // 찾은 문자열의 개수를 저장할 변수
        int N; // 테스트 케이스 번호를 저장할 변수
        
        // 테스트 케이스 번호, 찾을 문자열, 문장을 차례대로 입력받음
        cin >> N;
        cin >> ob >> line;
        
        // 문장의 길이에서 찾을 문자열의 길이를 빼고 1을 더한 만큼 반복
        for(int i=0;i<line.size() - ob.size() + 1; i++){
            // 찾을 문자열이 일치하는지 확인하는 플래그
            bool flag = true;
            // 찾을 문자열의 길이만큼 반복하며 각 문자가 일치하는지 확인
            for(int j=0;j<ob.size();j++){
                if(ob[j] != line[i+j]){
                    flag = false;
                    break;
                }
            }
            // 찾을 문자열이 일치하면
            if(flag){
                // 개수를 증가시키고
                ans++;
                // 다음 찾을 위치로 이동
                i += ob.size() - 1;
            }
        }
        
        // 테스트 케이스 번호와 찾은 개수를 출력
        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}