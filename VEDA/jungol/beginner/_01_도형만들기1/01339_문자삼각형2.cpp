#include<iostream>

using namespace std;

char arr[105][105];
int main() {
    int N;
    cin >> N;

    char ch = 'A';
    if (N % 2 == 0 || N < 1 || N > 100) {
        cout << "INPUT ERROR";
        return 0;
    }
    
    for (int i = N / 2; i >= 0; i--) {
        for (int j = i; j < N - i; j++) {
            arr[j][i] = ch++;

            if (ch == 'Z' + 1)
                ch = 'A';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == '\0')
                cout << "  ";
            else
                cout << arr[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}