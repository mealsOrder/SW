#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    set<string, greater<string>> s;

    for (int i = 0; i < N; i++) {
        string name, op;
        cin >> name >> op;
        if (op == "enter") s.insert(name);
        else s.erase(name);
    }

    for (auto& name : s)
        cout << name << '\n';

    return 0;
}
