#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#pragma warning ( disable : 4996 )

#define MAX_MEMORY 5

using namespace std;

void saveMemory(int data);

bool checkFullMemory();

bool checkFrozen();

void makeRun();

void printMemory();

void Selectminimum();

void writeRunFile();

void lastDataClear();

void printRun();

int memory[MAX_MEMORY];

bool written[MAX_MEMORY];

bool frozen[MAX_MEMORY];

int lastData = 0;

int cnt_partition = 0;

int minIndex;

int runArr[100][100];
int main() {

	

	int num = 0;

	int i = 0;

	int buf = 0;
	
	int test = 0; 

	int  freeze =0 , runSize[100], runNum, seqIter, min, minIndex, freezeArr[5], bufferSize;
	
	ifstream file("replacement_input.txt");
	if (!file.is_open()) {
		cout << "file open fail! PATH : replacement_input.txt" << endl;
	} else {
		cout << "OPEN." << endl;
	}

	ofstream fout;
	fout.open("replacement_output.txt");


	while (!file.eof()) {

		file >> test;
		
		while(test>0){
			
			file >> num;
			
			int* seq = new int[num];
			
			int buffer[5];
			
			for(int i=0;i<num;i++){
				file >> seq[i];
			}
			
			if(num>=5){
				runNum = 0;
				seqIter = 0;
				bufferSize = 0;
				
				for(int i=0;i<5;i++,seqIter++){
					buffer[i] = seq[seqIter];
				}
				
				while(seqIter<num){
					runSize[runNum]=0;
					freeze=0;
					
					while(freeze<5 && seqIter<num){
						min = buffer[0];
						minIndex=0;
						
						for(int i=1;i<5;i++){
							if(buffer[i]<min){
								min=buffer[i];
								minIndex=i;
							}
						}
						
						// 버퍼의 최소값을 런에 넣는다
						runArr[runNum][runSize[runNum]] = min;

						// 만약 다음 숫자가 런안의 최대값 보다 크면 freezeArr에 동결시키고 freeze값 하나 증가
						if (buffer[minIndex] > seq[seqIter]) { 
							buffer[minIndex] = 999;
							freezeArr[freeze] = seq[seqIter];
							freeze++;
						}
						// 그렇지 않을 경우 
						else {
							buffer[minIndex] = seq[seqIter];
						}
						runSize[runNum]++;
						seqIter++;
						
					}
					
					// 동결 숫자가 5이면 
					if (freeze == 5) {
						for (int i = 0; i < 5; i++) {
							buffer[i] = freezeArr[i];
						}
					}
					else {
						sort(buffer, buffer + 5);
						for (int i = 0; i < 5 - freeze; i++) {
							runArr[runNum][runSize[runNum]] = buffer[i];
							runSize[runNum]++;
						}
						for (int i = 0; i < freeze; i++) {
							buffer[i] = freezeArr[i];
						}
					}
					bufferSize = freeze;
					// 모두 처리하고 런 갯수를 하나 증가시켜준다 
					runNum++;

				}
				if (bufferSize > 0) { // if there is any frozen number in the buffer, then just put it in the next run and fileish the process
					sort(buffer, buffer + bufferSize);
					runSize[runNum] = bufferSize;
					for (int i = 0; i < bufferSize; i++) {
						runArr[runNum][i] = buffer[i];
					}
					runNum++;
				}

				fout << runNum << "\n";
				
				for (int i = 0; i < runNum; i++) {
					for (int j = 0; j < runSize[i]; j++) {
						fout << runArr[i][j] << " ";
					}
					fout << "\n";
				}

			}
			else {
				sort(seq, seq + num);
				fout << 1 << "\n";
				for (int i = 0; i < num; i++) {
					fout << seq[i] << " ";
				}
				fout << "\n";
			}
			delete[] seq;
			test--;	
					
					
					
					
		}
	}
		
	

	file.close();


}

//비어있는 메모리에 입력값 저장

void saveMemory(int data) {

	int i = 0;



	for (i = 0; i < MAX_MEMORY; i++) {

		if (written[i] == false) {

			memory[i] = data;

			written[i] = true;

			break;

		}

	}

}



//메모리 상태 체크

bool checkFullMemory() {

	//메모리에 데이터가 다 들어가 있으면 true, 없으면 false

	int i = 0;

	int cnt = 0;



	for (i = 0; i < MAX_MEMORY; i++) {

		if (written[i] == true) {

			cnt++;

		}

	}



	if (cnt != MAX_MEMORY) {

		return false;

	}

	else {

		return true;

	}



}



//빙결상태 체크

bool checkFrozen() {

	// 전체 빙결상태이면 true, 아니면 false

	int i = 0;

	int cnt = 0;



	for (i = 0; i < MAX_MEMORY; i++) {

		if (frozen[i] == true) {

			cnt++;

		}

	}



	if (cnt != MAX_MEMORY) {

		return false;

	}

	else {

		return true;

	}



}



//런만들기

void makeRun() {



	int i;



	Selectminimum();



	if (checkFrozen()) {

		cout << "!!!!!!!!!!!!!!전체 빙결(분할 완료)!!!!!!!!!!!!!!!!!" << endl;

		cnt_partition++;

		lastData = 0;



		for (i = 0; i < MAX_MEMORY; i++) {

			frozen[i] = false;

		}

		Selectminimum();

	}



	writeRunFile();

}



//조건에 맞는 미니멈값 찾기

void Selectminimum() {

	int i=0;

	minIndex = 0;



	//프로즌상태가 아니고, 라스트데이터보다 값이 크며, 현재 비교대상 메모리보다 작을 때 mindIndex 교체

	for (i = 0; i < MAX_MEMORY; i++) {

		if ((memory[i] < lastData)) {

			frozen[i] = true;

		}

	}



	//비교 대상 찾기 (프로즌 상태가 아닌 수)

	i = 0;

	while(i < MAX_MEMORY) {

		if (frozen[i] != true) {

			minIndex = i;

			break;

		}

		i++;

	}



	//비교하면서 조건에 맞는 인덱스 찾기	

	for (i=0; i < MAX_MEMORY; i++) {

		if ((frozen[i] == false) && (memory[i] > lastData) && (memory[minIndex] >= memory[i])) {

			minIndex = i;

		}

	}



	printMemory();

}



//파일에 런 쓰기입력

void writeRunFile() {

	char file_name[20];

	

	ofstream outfile;



	//파일이름 설정

	itoa(cnt_partition + 1, file_name, 10);

	strcat(file_name, "_partition.txt");



	outfile.open(file_name, ios::app);



	//outfile << memory[minIndex] << " ";

	outfile << " " << memory[minIndex];

	lastData = memory[minIndex];



	outfile.close();

	written[minIndex] = false;

}



//현재 메모리에 들어가있는 값 출력

void printMemory() {

	int i;



	cout << "\n//////////////////////////////////////////////" << endl;



	for (i = 0; i < MAX_MEMORY; i++) {

		if (frozen[i] == true) {

			cout << "(";

		}

		cout << memory[i];

		if (frozen[i] == true) {

			cout << ") ";

		} else {

			cout << " ";

		}

	}



	cout << "\n//////////////////////////////////////////////" << endl;

}





//런파일들을 화면에 출력

void printRun() {

	int i;

	ifstream file;

	int buf;

	char file_name[20];



	cout << "\n----------------------------------------------" << endl;



	for (i = 0; i <= cnt_partition; i++) {

		cout << i + 1 << "번 분할////" << endl;



		memset(file_name, 0, sizeof(file_name));

		itoa(i + 1, file_name, 10);

		strcat(file_name, "_partition.txt");



		file.open(file_name);



		while (!file.eof()) {

			file >> buf;

			cout << buf << " ";

		}

		file.close();

		cout << "\n////////////////////////////////////////" << endl;

	}

	cout << "\n----------------------------------------------" << endl;

}



//마지막 남은 데이터 처리

void lastDataClear() {

	int i = 0;



	while (i < MAX_MEMORY) {

		if (written[i] == true) {

			minIndex = i;

			break;

		}

		i++;

	}



	for (i = 0; i < MAX_MEMORY; i++) {

		if ((written[i] == true) && (memory[minIndex] > memory[i])) {

			minIndex = i;

		}

	}



	writeRunFile();



}

