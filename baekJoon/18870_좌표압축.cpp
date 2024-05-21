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
// ���ۺ��� ������ �ߺ��� ���̵��� �ڷ� �����µ�
// unique�� �ߺ��� ���̵��� ù��° �ּҸ� ��ȯ��
unique(v.begin(),v.end())

// a~b���� ��������
erase(a,b)

// ��� ���� : ���ĵǾ� �־����!
lower_bound : ã������ key������ ���ų� ū ���ڰ� 
�迭 ���°���� ó�� �����ϴ� ��ġ�� �ݺ��ڷ� ����

upper_bound : ã������ key������ �۰ų� ���� ���ڰ� 
�迭 ���°���� ó�� �����ϴ� ��ġ�� �ݺ��ڷ� ����
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
        // lower_bound() �Լ��� ��ȯ�ϴ� �ݺ��ڿ��� v.begin()�� ����, 
        // �Էµ� ���� �迭���� �� ��° ��ġ�� �ִ����� �� �� �ִ�.
        cout << lower_bound(v.begin(),v.end(),r[i]) - v.begin() << " ";
    }
    return 0;
}