#include<iostream>  
#include<vector>    
#include<algorithm> 
#include<queue>     
using namespace std;

const int MAX = 1001;  // �Է� �迭�� �ִ� ũ�� ��� ����
int A[MAX];           // �Է� ���� ���ڵ��� ������ �迭
int DP[MAX];         // ���� ���α׷����� ���� �迭

int main(){
    int N;  // �Է� ���� ������ ����
    
    // ������ ���� N �Է� �ޱ�
    cin >> N;
    
    // �� ���ڸ� �Է� �޾� A �迭�� ����
    for(int t=1;t<=N;t++){
        cin >> A[t];
    }
    

    for(int i=1;i<=N;i++){
        // ���� ���� A[i]�� �����ϴ� ���� �� ���� �κ� ������ ���� �ʱ�ȭ
        DP[i] = A[i];
        
        // ���� ���ڵ� A[j]�� ���Ͽ� ���� �� ���� �κ� ���� ���� ����
        // DP[a]=b : a�� �ε��� ������ ���� ū �κ� ������ ��b
        for(int j=1;j<i;j++){
            if(A[i] > A[j] ){
                DP[i] = max(DP[i],A[i]+DP[j]);
            }
        }
    }
    
    // ���� �� ���� �κ� ������ ���� ã��
    int ans=0;
    for(int i=1;i<=N;i++){
        ans = max(ans,DP[i]);
    }
    
    // ���� �� ���� �κ� ������ ���� ���
    cout << ans << endl;
    
    return 0;
}