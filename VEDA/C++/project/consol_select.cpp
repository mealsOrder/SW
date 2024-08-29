#include <iostream>
#include <conio.h>  // _getch() 함수를 사용하기 위함
#include <windows.h> // 커서 이동을 위해 필요한 헤더

using namespace std;

const int rows = 4;
const int cols = 4;
int arr[rows][cols] = {
    {0, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0}
};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printArray(int currentRow, int currentCol) {
    system("cls");

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == currentRow && j == currentCol) {
                cout << "[ " << arr[i][j] << " ] ";  // 현재 선택된 요소를 강조
            } else {
                cout << "  " << arr[i][j] << "   ";
            }
        }
        cout << endl;
    }

    // 스테이터스 영역 출력
    gotoxy(0, rows + 2);
    cout << "현재 위치: (" << currentRow + 1 << ", " << currentCol + 1 << ")";
    cout << "  값: " << arr[currentRow][currentCol] << endl;
}

int main() {
    int currentRow = 0, currentCol = 0;

    while (true) {
        printArray(currentRow, currentCol);

        int key = _getch();

        // 화살표 키 조작
        if (key == 224) {
            key = _getch();

            if (key == 72 && currentRow > 0) {          // 위쪽 화살표
                currentRow--;
            }
            else if (key == 80 && currentRow < rows - 1) { // 아래쪽 화살표
                currentRow++;
            }
            else if (key == 75 && currentCol > 0) {     // 왼쪽 화살표
                currentCol--;
            }
            else if (key == 77 && currentCol < cols - 1) { // 오른쪽 화살표
                currentCol++;
            }
        }
        // ESC 키로 종료
        else if (key == 27) {
            break;
        }
    }

    return 0;
}
