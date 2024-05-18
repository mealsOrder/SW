#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

/*
문자열 정렬 문제를 해결하기 위한 것입니다.

(방법1)
s 배열에는 문자열 변환을 위한 기준 문자열이 저장되어 있습니다.
arr 배열에는 입력 문자열의 인덱스가 저장됩니다.
brr 배열에는 입력 받은 문자열이 저장됩니다.
ans 배열에는 정렬된 문자열이 저장됩니다.
입력 받은 문자열을 s 배열의 문자열과 비교하여 arr에 인덱스를 저장 
이후 arr 배열을 정렬하고, 다시 s 배열의 문자열을 순회하여 정렬된 문자열을 ans에 저장
최종적으로 ans 배열의 문자열을 출력
시간과 메모리가 넉넉하게 주어져서 이렇게 풀어도 되는거임 가능하면 방법2로

(방법2)
사실 진짜 정렬되고 안되고는 중요하지 않고
간단하게 내가 0~9를 몇번 입력받았는지 세어서 그 수만큼 문자열을 출력하는 방법
으로 풀면 아주 간단하게 풀 수 있을 것 같음

*/



const int MAX = 10001; // 최대 입력 수 

// 문자열 변환을 위한 배열
string s[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"}; 
int idx[10]; // s 배열의 인덱스 저장을 위한 배열
int arr[MAX]; // 입력 문자열의 인덱스 저장을 위한 배열
string brr[MAX]; // 입력 문자열 저장을 위한 배열
string ans[MAX]; // 정렬된 문자열 저장을 위한 배열

int main() {
    int T; // 테스트 케이스 수
    
    cin >> T; // 테스트 케이스 수 입력

    for (int t = 1; t <= T; t++) { // 테스트 케이스 수만큼 반복
        string K; // 테스트 케이스의 이름
        int N; // 입력 문자열의 수

        cin >> K >> N; // 테스트 케이스 이름과 입력 문자열의 수 입력

        for (int i = 0; i < N; i++) { // 입력 문자열 수만큼 반복
            cin >> brr[i]; // 입력 문자열 저장
            
            for (int j = 0; j < 10; j++) { // 문자열 인덱스 찾기
                if (brr[i] == s[j]) { // 입력 문자열이 s 배열의 문자열과 일치하면
                    arr[i] = j; // arr 배열에 인덱스 저장
                }
            }
        }

        sort(arr, arr + N); // arr 배열 정렬

        for (int i = 0; i < N; i++) { // 정렬된 arr 배열 순회
            for (int j = 0; j < 10; j++) { // s 배열 순회
                if (arr[i] == j) { // arr 배열의 인덱스와 일치하면
                    ans[i] = s[j]; // ans 배열에 s 배열의 문자열 저장
                    break;
                }
            }
        }

        cout << "#" << t << endl; // 테스트 케이스 번호 출력
        for (int i = 0; i < N; i++) { // 정렬된 문자열 출력
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}