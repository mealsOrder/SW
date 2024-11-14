#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
const int MX = 1001;
int arr[MX];
deque<pair<int,int>> s;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        s.push_back({a, i});
    }

    while(!s.empty()) {
        int cur = s.front().first;
        int curI = s.front().second;
        s.pop_front();
        cout << curI << " ";

        if(cur >= 0) {
            for(int i = 1; i < cur; i++) {
                if(s.empty()) break; // 덱이 비어있는지 체크
                int n = s.front().first;
                int idx = s.front().second;
                s.pop_front();
                s.push_back({n, idx});
            }
        } else {
            for(int i = 1; i <= -1 * cur; i++) {
                if(s.empty()) break; // 덱이 비어있는지 체크
                int n = s.back().first;
                int idx = s.back().second;
                s.pop_back();
                s.push_front({n, idx});
            }
        }
    }

    return 0;
}