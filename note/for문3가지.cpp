#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; ++i) {
        cout << "일반 for 문: " << i << endl;
    }

    for (int num : numbers) {
        cout << "향상된 for 문: " << num << endl;
    }

    for_each(numbers.begin(), numbers.end(), [](int num) {
        cout << "for_each 문: " << num <<  endl;
    });

    return 0;
}