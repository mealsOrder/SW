#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
// CCW 알고리즘은 세 점의 좌표를 이용하여 
//그것들이 이루는 삼각형의 방향을 판단하는데 사용된다.

/**
 * 1) 평면 상에서 세점 ABC가 주어졌을때,
 * 이 세점이 이루는 벡터 AB와 AC의 외적(cross Product)를 계산
 * CCW = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1)
 * 2) 외적의 결과가 양수이면 반시계 방향
 *    외적의 결과가 음수이면 시계 방향
 *    외적의 결과가 0 이면 세점이 일직선상에 있음
 */

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x1,x2,x3;
    int y1,y2,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int ans=(x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
    if(ans < 0) cout << "-1\n";
    else if(ans > 0) cout << "1\n";
    else cout << "0\n";
    return  0;
}