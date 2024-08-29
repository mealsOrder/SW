#include <iostream>
#include <conio.h>  // _getch() 함수를 사용하기 위함
#include <windows.h> // 커서 이동을 위해 필요한 헤더

using namespace std;

// 우리가 입력받아야 할 가로 세로
const int rows = 4;
const int cols = 4;
const int deps = 2;

// 유저 정보와 차량 정보를 저장할 구조체 정의
struct VehicleInfo{
    string userId; 
    string vehicleType;
    string vehiclePlate;
};

// 2차원 배열로 유저 정보와 차량 정보 저장 (일부 칸은 비워둠)
VehicleInfo parkingLot[rows][cols] ={
   {{"user1", "Sedan", "12AB34"},{"user2", "SUV", "23CD45"},{"", "", ""},{"user4", "Motorbike", "45GH67"}},
   {{"user5", "Van", "56IJ78"},{"user6", "Convertible", "67KL89"},{"user7", "SUV", "78MN90"},{"user8", "Sedan", "89OP12"}},
   {{"user9", "Hatchback", "90QR34"},{"", "", ""},{"user11", "Truck", "34UV78"},{"user12", "Motorbike", "56WX90"}},
   {{"", "", ""},{"user14", "Van", "90AB34"},{"user15", "Sedan", "12CD45"},{"", "", ""}}
};

// 해당 좌표로 커서를 이동 시키는 함수
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 현
void printArray(int currentRow, int currentCol){
    system("cls");

    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            if (i == currentRow && j == currentCol){
                cout << "[ X ] ";  // 현재 선택된 요소를 강조
            } else{
                if (parkingLot[i][j].userId.empty()){
                    cout << "[ 0 ] ";  // 비어있는 칸
                } else{
                    cout << "[ 1 ] ";  // 채워진 칸
                }
            }
        }
        cout << endl;
    }

    // 스테이터스 영역 출력
    gotoxy(0, rows + 2);
    VehicleInfo currentInfo = parkingLot[currentRow][currentCol];
    if (!currentInfo.userId.empty()){
        cout << "유저 ID: " << currentInfo.userId << endl;
        cout << "차량 종류: " << currentInfo.vehicleType << endl;
        cout << "차량 번호: " << currentInfo.vehiclePlate << endl;
    } else{
        cout << "이 위치는 비어있습니다." << endl;
    }
}

int main(){
    int currentRow = 0, currentCol = 0;

    while (true){
        printArray(currentRow, currentCol);

        int key = _getch();

        // 화살표 키 조작
        if (key == 224){
            key = _getch();

            if (key == 72 && currentRow > 0){          // 위쪽 화살표
                currentRow--;
            }
            else if (key == 80 && currentRow < rows - 1){ // 아래쪽 화살표
                currentRow++;
            }
            else if (key == 75 && currentCol > 0){     // 왼쪽 화살표
                currentCol--;
            }
            else if (key == 77 && currentCol < cols - 1){ // 오른쪽 화살표
                currentCol++;
            }
        }
        // ESC 키로 종료
        else if (key == 27){
            break;
        }
    }

    return 0;
}
