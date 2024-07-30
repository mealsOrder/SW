#include<iostream>
#include<string>
using namespace std;
class BaseIo{
public:
    int mode;
};

class In : public BaseIo{
public:
    int readPos;
};

class Out : public BaseIo{
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
    // io.mode = 5; // 중복 상속 되어 io 객체에 mode가 두개 있기 때문에 
                    // 컴파일러는 어떤 mode인지 판단할 수 없어서 컴파일 에러

    return 0;
}