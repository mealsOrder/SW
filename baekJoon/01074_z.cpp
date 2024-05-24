#include<iostream>
#include<cmath>
using namespace std;

#define MAX 16

int N;
int cnt;
int R,C;

void divideConquer(int x,int y,int len){
    if(x==R && y==C){
        cout << cnt << '\n';
        exit(0);
    }


    if(x <= R && y<=C && x+len > R && y+len > C){
        int newLen = len/2;
        divideConquer(x,y,newLen);
        divideConquer(x,y+newLen,newLen);
        divideConquer(x+newLen,y,newLen);
        divideConquer(x+newLen,y+newLen,newLen);
    }
    else{
        cnt += len * len;
    }
}

int main(){
    cin >> N>>R>>C;
    divideConquer(0,0,pow(2,N));

    return 0;
}