#include<iostream>
#include<set>
#include<string>
#include<cstring>

using namespace std;

/*
set�� �ߺ����� �����ϴ� �ڷᱸ���̴�. �����̶�� �����ϸ� �ȴ�!
*/

// set�� ���ø� Ŭ�����̱� ������ set��ü�� ������ ������
// set�� �� ���ҵ��� Ÿ���� ������� �Ѵ�.

set<int>a;
set<int>s;
set<string>c;

int main(){
    
    // ���� ����ֱ�
    a.insert(3);

    int arr[10] = {1,1,2,3,4,4,5,5,6,7};
    // 1,4,5 ���� 2���� �ߺ��Ǿ� �ִ� �迭�� set�� ����

    for(int i=0;i<10;i++){
        s.insert(arr[i]);

    }

    cout << "set s�� ũ��: " << s.size() << endl;

    // ����
    s.erase(1);

    // set ��ü�� ����ִ��� Ȯ���Ϸ��� 
    // s.empty() size 0 �̸� ����ִ°�
    // s.empty()�� ��������� 1 �ƴϸ� 0 ����
    cout << s.empty() << " ";  
    for(set<int>::iterator i=s.begin();i!=s.end();i++){
        cout << *i << " ";
    }
    cout << endl;
    

    return 0;
}