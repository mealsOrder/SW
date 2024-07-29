#include<iostream>

using namespace std;

class Person{
public:
    int money;
    void addMoney(int money){
        this->money+=money;
    }

    static int sharedMoney;
    static void addShared(int n){
        sharedMoney += n;
    }
};

int Person::sharedMoney = 10;
int main(){
    // 스테틱 맴버 호출하는 방법
    // 1. 클래스 이름으로 Person::sharedMoney
    // 2. 객체를 만들어서 호출 p.sharedMoney
    Person::addShared(50);
    cout << Person::sharedMoney << '\n';

    Person p;
    p.money = 100;
    p.sharedMoney = 200;
    Person::sharedMoney = 300;
    Person::addShared(100);

    cout << p.money << " " << Person::sharedMoney << '\n';
    cout << p.sharedMoney << '\n';
    return 0;   
}