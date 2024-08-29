#include <iostream>
#include <conio.h>  // _getch() 함수를 사용하기 위함
#include <windows.h> // 커서 이동을 위해 필요한 헤더

using namespace std;

const int rows = 4;
const int cols = 4;

// 유저 정보와 차량 정보를 저장할 구조체 정의
struct VehicleInfo {
    string userId;
    string vehicleType;
    string vehiclePlate;
};

// 2차원 배열로 유저 정보와 차량 정보 저장
VehicleInfo parkingLot[rows][cols] = {
    {{"", "", ""}, {"user2", "SUV", "23CD45"}, {"user3", "Truck", "34EF56"}, {"user4", "Motorbike", "45GH67"}},
    {{"user5", "Van", "56IJ78"}, {"user6", "Convertible", "67KL89"}, {"user7", "SUV", "78MN90"}, {"user8", "Sedan", "89OP12"}},
    {{"user9", "Hatchback", "90QR34"}, {"user10", "SUV", "12ST56"}, {"user11", "Truck", "34UV78"}, {"user12", "Motorbike", "56WX90"}},
    {{"user13", "Convertible", "78YZ12"}, {"user14", "Van", "90AB34"}, {"user15", "Sedan", "12CD45"}, {"user16", "SUV", "23EF56"}}
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
                cout << "[ X ] ";  // 현재 선택된 요소를 강조
            } else {
                cout << "[   ] ";  // 선택되지 않은 요소
            }
        }
        cout << endl;
    }

    // 스테이터스 영역 출력
    gotoxy(0, rows + 2);
    VehicleInfo currentInfo = parkingLot[currentRow][currentCol];
    cout << "유저 ID: " << currentInfo.userId << endl;
    cout << "차량 종류: " << currentInfo.vehicleType << endl;
    cout << "차량 번호: " << currentInfo.vehiclePlate << endl;
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
