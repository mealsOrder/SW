#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int col, row, N;
    cin >> col >> row >> N;

    vector<int> h ={0, row}, v ={0, col};

    while (N--){
        int d, p;
        cin >> d >> p;
        (d ? v : h).push_back(p);
    }

    sort(h.begin(), h.end());
    sort(v.begin(), v.end());

    int maxH = 0, maxV = 0;
    for (int i = 1; i < h.size(); i++) maxH = max(maxH, h[i] - h[i - 1]);
    for (int i = 1; i < v.size(); i++) maxV = max(maxV, v[i] - v[i - 1]);

    cout << maxH * maxV << '\n';
    return 0;
}
