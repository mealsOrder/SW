#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class GameObject{ // 추상 클래스
protected:
    int distance;
    int x,y;
public:
    GameObject(int startX,int startY,int distance){
        this->x = startX;
        this->y = startY;
        this->distance = distance;
    }
    virtual ~GameObject(){};
    virtual void move() = 0;
    virtual char getShape() = 0;

    int getX(){return x;}
    int getY(){return y;}
    bool collide(GameObject *p){
        if(this->x == p->getX() && this->y == p->getY())return true;
        else return false;
    }
};

class Human : public GameObject{
public:
    Human(int startX,int startY,int dis) : GameObject(startX,startY,dis){}

    void move(){
        char key;
        cout << "왼쪽(a), 아래(s), 위(d), 오른쪽(f) >> ";
        cin >> key;
        cout << '\n';
        // 왼쪽 키 누르면
        if(key == 'a'){
            // 왼쪽 지도 밖 좌표로 나가면 오른쪽 끝으로 이동 시켜준다
            if(y-distance<0) y = 20 +y - distance;
            else y -= distance;
        }
        // 아래 키 누르면
        else if(key == 's'){
            // 아래쪽 지도 밖 좌표로 나가면 위쪽 끝으로 이동시켜 준다.
            if(x+distance>9) x = x + distance - 10;
            else x+= distance;
        }
        // 위 키 누르면
        else if(key == 'd'){
            // 위쪽 지도 밖 좌표로 나가면 아래쪽 끝으로 이동시켜 준다
            if(x- distance < 0) x = 10 + x - distance;
            else x -= distance;
        }
        // 오른쪽 지도 밖 좌표로 나가면 왼쪽 끝으로 이동 시켜 준다
        else if(key == 'f'){
            if(y+distance>19) y = y + distance - 20;
            else y+=distance;
        }
    }
    char getShape(){
        return 'H';
    }
};

class Monster : public GameObject{
public:
    Monster(int startX,int startY,int dist) : GameObject(startX,startY,dist){
        srand((unsigned)time(0));
    }
    void move(){
        int num;
        num = rand()%2;
        switch(num){
        case 0:
            if(x - distance<0) x = 10 + x - distance;
            else x-= distance;
            break;
        case 1:
            if(x+distance>9) x = x + distance - 10;
            else x+=distance;
            break;
        }
        num = rand()%2;
        switch(num){
        case 0:
            if(y-distance < 0) y = y - distance + 20;
            else y-=distance;
            break;
        case 1:
            if(y+distance>19) y = y + distance - 20;
            else y+=distance;
            break;
        }

    }
    char getShape(){
        return 'M';
    }
};

class Food : public GameObject{
    int count;
public:
    Food(int startX,int startY,int dis) : GameObject(startX,startY,dis){
        srand((unsigned)time(0));
        count = 0;
    }
    void move(){
        int n1,n2;
        n1 = rand()%5;
        n2 = rand()%4;
        if(n1>=1 && n1<=2){
            switch(n2){
            case 0:
				if (y - distance < 0) y = 20 + y - distance;
				else y -= distance;
				break;
			case 1:
				if (x + distance > 9) x = x + distance - 10;
				else x += distance;
				break;
			case 2:
				if (x - distance < 0) x = 10 + x - distance;
				else x -= distance;
				break;
			case 3:
				if (y + distance > 19) y = y + distance - 20;
				else y += distance;
				break;
            }
        }
    }


    char getShape(){
        return '@';
    }
};
class Game{
public:
    void run(){
        bool flag = true;
        Human* h = new Human(0,0,1);
        Monster* m = new Monster(5,5,2);
        Food* f = new Food(8,9,1);

        cout << "** Human의 Food 먹기 게임을 시작합니다.\n\n";
        while(flag){
            for(int i=0;i<10;i++){
                for(int j=0;j<20;j++){
                    if(m->getX() == i && m->getY() == j)cout << m->getShape();
                    else if(h->getX() == i && h->getY() == j)cout << h->getShape();
                    else if(f->getX() == i && f->getY() == j)cout << f->getShape();
                    else cout << '-';
                }
                cout << '\n';
            }
            if(m->collide(h)){
                cout << "Human is Loser!!\n";
                cout << "Captured by a monster...\n\n";
                flag = false;
                break;
            }
            else if(m->collide(f)){
                cout << "Human is Loser!!\n";
                cout << "The monster ate the food...\n\n";
                flag = false;
                break;
            }
            else if(h->collide(f)){
                cout << "Human is Winner!!\n";
                cout << "You ate the food!!\n\n";
                break;
            }

            h->move();
            m->move();
            f->move();
        }
    }
};
int main(){
    Game* g = new Game();
    g->run();
    delete g;


    return 0;
}