#ifndef SHAPE_H
#define SHAPE_H

class Shape{
    Shape* next;
protected:
    virtual void draw() = 0; // 순수 가상 함수 : 코드를 가지지 않으므로, Shape클래스에 구현부에 draw를 구현하면 안된다!
public:
    Shape(){next = NULL;};
    virtual ~Shape(){}
    void paint();
    Shape* add(Shape* p);
    Shape* getNext() { return next;}
};

#endif