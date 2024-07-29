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
    Person p;
    p.money = 100;
    p.sharedMoney = 200;

    Person q;
    q.money = 150;
    q.addMoney(200);
    q.addShared(200);

    cout << p.money << " " << q.money << '\n';
    cout << p.sharedMoney <<" " << q.sharedMoney << '\n';
    return 0;   
}