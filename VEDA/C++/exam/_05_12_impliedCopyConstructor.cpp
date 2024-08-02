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

void f(Person person)           // 2. '값에 의한 호출'로 객체가 전달될 때
{                               // person 객체의 복사 생성자 호출
    person.changeName("dummy");
}

Person g()
{
    Person mother(2,"Jane");
    return mother;          // 3. 함수에서 객체를 리턴할 때, mother 객체의
                            // 복사본 생성. 본사본의 복사 생성자 호출
}
int main()
{
    Person father(1,"Kitae");
    Person son = father; // 복사 생성자 호출
                         // 1. 객체로 초기화하여 객체가 생성될 때, 
                         // son 객체의 복사 생성자 호출
    f(father);  // 복사 생성자 호출
    g();        // 복사 생성자 호출

    return 0;
}