#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>A; // 숫자 카드 집합 A
vector<int>B; // 질문 집합 B
vector<int>C; // 결과 저장 벡터

// 이진 탐색 함수
// v1: 탐색할 벡터, target: 찾을 타겟 값, left/right: 탐색 범위
int binarySearch(vector<int>& v1, int target, int left, int right){
    // 탐색 범위가 유효하면 반복
    while(left <= right){
        int mid = (left + right) / 2; // 중간 인덱스
        if (v1[mid] == target){       // 찾은 경우
            return 1;
        } else if (v1[mid] < target){ // 중간 값이 타겟보다 작은 경우
            left = mid + 1;           // 오른쪽 반으로 탐색 범위 좁힘 
        } else{                       // 중간 값이 타겟보다 큰 경우
            right = mid - 1;          // 왼쪽 반으로 탐색 범위 좁힘
        }
    }
    return 0; // 찾지 못한 경우
}

int main() {
    int N, M;

    cin >> N; // 숫자 카드 개수 입력
    for(int i=0;i<N;i++){
        int a;
        cin >> a; // 숫자 카드 입력
        A.push_back(a);
    }
    cin >> M; // 질문 개수 입력
    for(int i=0;i<M;i++){
        int b;
        cin >> b; // 질문 입력
        B.push_back(b);
    }
    
    sort(A.begin(),A.end()); // 숫자 카드 집합 A 정렬
    
    for(int i=0;i<M;i++){ // 질문 개수만큼 반복
        C.push_back(binarySearch(A, B[i], 0, N-1)); // 이진 탐색을 통해 결과 저장
    }
    
    for(int i=0;i<M;i++){ // 결과 출력
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}