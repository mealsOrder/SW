#include <iostream>
using namespace std;

int main() {
  int a[5][5];
  int n, cnt = 0;
  int xCnt = 0;
  int order = 0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> n;
      order++;
      // (1) a의 위치를 찾고
      // (2) a를 지우고
      // (3) 몇 줄 지워졌는지 파악
      // (4) 3줄이상 지워졌으면 끝!

      for (int k = 0; k < 5; k++) {
        for (int p = 0; p < 5; p++) {
          if (a[k][p] == n) {
            a[k][p] = -1;
          }
        }
      }

      cnt = 0;

      // 가로줄
      for (int k = 0; k < 5; k++) {
        xCnt = 0;
        for (int p = 0; p < 5; p++) {
          if (a[k][p] == -1) {
            xCnt++;
          }
        }

        if (xCnt == 5) cnt++;
      }

      // 세로줄
      for (int k = 0; k < 5; k++) {
        xCnt = 0;
        for (int p = 0; p < 5; p++) {
          if (a[p][k] == -1) {
            xCnt++;
          }
        }

        if (xCnt == 5) cnt++;
      }

      if (a[0][0] == -1 &&
          a[1][1] == -1 &&
          a[2][2] == -1 &&
          a[3][3] == -1 &&
          a[4][4] == -1) cnt++;

      if (a[0][4] == -1 &&
          a[1][3] == -1 &&
          a[2][2] == -1 &&
          a[3][1] == -1 &&
          a[4][0] == -1) cnt++;

      if (cnt >= 3) {
        cout << order << endl;
        return 0;
      }
    }
  }

  return 0;
}