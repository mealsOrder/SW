#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
using namespace std;
// 깊은 복사 생성자를 가진 정상적인 Person 클래스

class Person
{
    char *name;
    int id;
public:
    Person(int id,const char* name);
    Person(const Person& p);
    ~Person();
    void changeName(const char *name);
    void show() { cout << id <<", " << name << '\n';}

};
Person::Person(int id,const char* name)
{
    this-> id = id;
    int len = strlen(name);
    this->name = new char[len+1];
    strcpy(this->name,name);
}
// 복사 생성자
Person::Person(const Person& p)
{
    this->id = p.id;
    int len = strlen(p.name);
    this->name = new char [len+1];
    strcpy(this->name,p.name);
    cout << "복사 생성자 실행, 원복 객체의 이름" << this->name << '\n';
}
Person::~Person()
{
    if(name) delete[] name;
}

void Person::changeName(const char *name)
{
    if(strlen(name) > strlen(this->name))return;
    strcpy(this->name,name);
}
int main()
{
    Person father(1,"Kitae");
    Person daughter(father); // 컴파일러가 디폴트 복사 생성자 호출
    cout << "daughter 객체 생성 직후 ----\n";
    father.show();
    daughter.show();

    daughter.changeName("Grace");
    cout << "daughter 이름을 Grace로 변경 한 후 ----\n";
    father.show();
    daughter.show();
    // daughter, father 순으로 소멸.
    // father이 소멸할 때 프로그램이 비정상 종료됨...
    return 0;
}