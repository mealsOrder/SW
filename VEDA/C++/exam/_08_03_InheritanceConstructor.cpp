#include<iostream>
#include<string>
using namespace std;
class TV{
private:
    int size;
public:
    // TV(){size = 20;}
    // TV(int size){this->size = size;}
    
    // 위 두줄을 합쳐서 한줄로 표현 해도 됨 대신 자식 클래스에서
    // 매개 변수가 있는 생성자를 호출하도록 지정 해줘야 오류가 안난다!
    TV(int size=20){this->size = size;}
    int getSize(){
        return size;
    }
};

// TV클래스를 상속받는 WideTV
class WideTV : public TV{
    bool videoIn;
public:
    // 상속 에서는 기본 생성자가 선언 되어 있지 않으면 컴파일 오류난다
    // 그래서 기본 생성자를 작성하거나 아래와 같이 생성자를 명시적으로 선택 해줘야 함
    WideTV(int size,bool videoIn) : TV(size) {
        this->videoIn = videoIn;
    }
    bool getVideoIn(){
        return videoIn;
    }
};

// WideTV클래스를 상속받는 SmartTV
class SmartTV : public WideTV{
    string ipAddr;
public:
    SmartTV(string ipAddr,int size) : WideTV(size,true) {
        this->ipAddr = ipAddr;
    }
    string getIpAddr(){
        return ipAddr;
    }
};

int main(){
    SmartTV htv("192.0.0.1",32);
    cout << "size = " << htv.getSize() << '\n';
    // boolalpha : bool 값을 true, false 로 출력되게 하는 조작자
    cout << "vidoIn = " << boolalpha << htv.getVideoIn() << '\n';
    cout << "ipAddr = " << htv.getIpAddr() << '\n';
    return 0;
}