#include<iostream>
#include"Shape.h"
#include"Circle.h"
#include"Line.h"
#include"Rect.h"
using namespace std;

int main(){
    Shape *pStart = NULL;
    Shape *pLast;

    pStart = new Circle();
    pLast = pStart;

    pLast = pLast->add(new Rect());
    pLast = pLast->add(new Circle());
    pLast = pLast->add(new Line());
    pLast = pLast->add(new Rect());

    // 현재 연결된 모든 도형을 화면에 그린다
    Shape* p = pStart;
    while(p != NULL){
        p->paint();
        p = p->getNext();
    }

    // 현재 연결된 모든 도형을 삭제한다
    p = pStart;
    while(p!=NULL){
        Shape* q = p->getNext(); // 다음 도형 주소 기억
        delete p;
        p = q;
    }
    return 0;
}