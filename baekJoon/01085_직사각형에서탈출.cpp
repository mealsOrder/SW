#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
using namespace std;

int main() {
    int x,y,w,h;

    cin >> x>>y>>w>>h;

    int ans = min(min(w-x,x),min(h-y,y));
    cout << ans << '\n';
    return 0;
}