#include<iostream>
#include<ctime>
#include<cstdio>
using namespace std;

class UpDown{
public:
    static int ans;
    static void print(int st,int en){
        cout << "답은 " << st << "과 " << en << "사이에 있습니다\n";
    }
    static void guess(string str,int& st, int& en,int& cnt){
        int num;
        if(cnt%2 == 0) str = "김인수";
        else str = "오은경";
        cout << str <<">>";
        cin >> num;

        if( num < ans){
            st = num;
            print(st,en);
            
        }else if(num > ans){
            en = num;
            print(st,en);
            
        }else{
            cout << str <<"가 이겼습니다!\n";
            return;
        }
        cnt++;
    }
};


int UpDown::ans = 0;

int main(){

    srand((unsigned)time(0));
    int n = rand();
    n = n%100;
    UpDown::ans = n;
    UpDown a;
    cout << UpDown::ans << '\n';
    cout << "up&down 게임을 시작합니다.\n";
    int ss = 0, ee =99,count=0;
    while(1){
        a.guess("김인수",ss,ee,count);
    }

    return 0;
}