#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;


int main(){
    // 10���� �׽�Ʈ ���̽��� ���� �ݺ�
    for(int t=1;t<=10;t++){
        string line,ob; // ����� ã�� ���ڿ��� ������ ����
        int ans = 0; // ã�� ���ڿ��� ������ ������ ����
        int N; // �׽�Ʈ ���̽� ��ȣ�� ������ ����
        
        // �׽�Ʈ ���̽� ��ȣ, ã�� ���ڿ�, ������ ���ʴ�� �Է¹���
        cin >> N;
        cin >> ob >> line;
        
        // ������ ���̿��� ã�� ���ڿ��� ���̸� ���� 1�� ���� ��ŭ �ݺ�
        for(int i=0;i<line.size() - ob.size() + 1; i++){
            // ã�� ���ڿ��� ��ġ�ϴ��� Ȯ���ϴ� �÷���
            bool flag = true;
            // ã�� ���ڿ��� ���̸�ŭ �ݺ��ϸ� �� ���ڰ� ��ġ�ϴ��� Ȯ��
            for(int j=0;j<ob.size();j++){
                if(ob[j] != line[i+j]){
                    flag = false;
                    break;
                }
            }
            // ã�� ���ڿ��� ��ġ�ϸ�
            if(flag){
                // ������ ������Ű��
                ans++;
                // ���� ã�� ��ġ�� �̵�
                i += ob.size() - 1;
            }
        }
        
        // �׽�Ʈ ���̽� ��ȣ�� ã�� ������ ���
        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}