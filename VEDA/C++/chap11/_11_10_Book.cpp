#include<iostream>
using namespace std;

class Book{
private:
    string title;
    string press;
    string author;
public:
    Book(string title="",string press="",string author=""){
        this->title = title;
        this->press = press;
        this->author = author;
    }

    friend ostream& operator<<(ostream& stream,Book b);
};

ostream& operator<<(ostream& stream,Book b){
    stream << b.title << "," << b.press << "," << b.author << '\n';
    return stream;
}

int main(){
    Book bk("소유","한국","에리");
    cout << bk;

    return 0;   

}