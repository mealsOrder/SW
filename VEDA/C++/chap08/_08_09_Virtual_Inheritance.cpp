#include<iostream>
#include<string>
using namespace std;
class BaseIo{
public:
    int mode;
};

class In : virtual public BaseIo{
public:
    int readPos;
};

class Out : virtual public BaseIo{
public:
    int writePos;
};

class Inout : public In, public Out {
public:
    bool safe;
};
int main(){
    Inout io;
    io.readPos = 10;
    io.writePos = 20;
    io.safe = true;
    io.mode = 5;// 가상 상속되어 mode 변수 공간이 하나만 생성되어 있어
                // mode 변수에 대한 모호성은 없다!

                // 가상 상속 
                // 장점 : 멤버 중복 상속 문제를 해결한 다중상속 가능!
                // 단점 : 실행 시간에 검사가 되므로 실행 시간이 길어진다
                //        부모가 많아지면 부모가 누구인지 찾는다고 느려짐 (트리구조)
    return 0;
}