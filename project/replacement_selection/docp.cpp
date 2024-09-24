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
						
						// ������ �ּҰ��� ���� �ִ´�
						runArr[runNum][runSize[runNum]] = min;

						// ���� ���� ���ڰ� ������ �ִ밪 ���� ũ�� freezeArr�� �����Ű�� freeze�� �ϳ� ����
						if (buffer[minIndex] > seq[seqIter]) { 
							buffer[minIndex] = 999;
							freezeArr[freeze] = seq[seqIter];
							freeze++;
						}
						// �׷��� ���� ��� 
						else {
							buffer[minIndex] = seq[seqIter];
						}
						runSize[runNum]++;
						seqIter++;
						
					}
					
					// ���� ���ڰ� 5�̸� 
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
					// ��� ó���ϰ� �� ������ �ϳ� ���������ش� 
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

//����ִ� �޸𸮿� �Է°� ����

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



//�޸� ���� üũ

bool checkFullMemory() {

	//�޸𸮿� �����Ͱ� �� �� ������ true, ������ false

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



//������� üũ

bool checkFrozen() {

	// ��ü ��������̸� true, �ƴϸ� false

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



//�������

void makeRun() {



	int i;



	Selectminimum();



	if (checkFrozen()) {

		cout << "!!!!!!!!!!!!!!��ü ����(���� �Ϸ�)!!!!!!!!!!!!!!!!!" << endl;

		cnt_partition++;

		lastData = 0;



		for (i = 0; i < MAX_MEMORY; i++) {

			frozen[i] = false;

		}

		Selectminimum();

	}



	writeRunFile();

}



//���ǿ� �´� �̴ϸذ� ã��

void Selectminimum() {

	int i=0;

	minIndex = 0;



	//��������°� �ƴϰ�, ��Ʈ�����ͺ��� ���� ũ��, ���� �񱳴�� �޸𸮺��� ���� �� mindIndex ��ü

	for (i = 0; i < MAX_MEMORY; i++) {

		if ((memory[i] < lastData)) {

			frozen[i] = true;

		}

	}



	//�� ��� ã�� (������ ���°� �ƴ� ��)

	i = 0;

	while(i < MAX_MEMORY) {

		if (frozen[i] != true) {

			minIndex = i;

			break;

		}

		i++;

	}



	//���ϸ鼭 ���ǿ� �´� �ε��� ã��	

	for (i=0; i < MAX_MEMORY; i++) {

		if ((frozen[i] == false) && (memory[i] > lastData) && (memory[minIndex] >= memory[i])) {

			minIndex = i;

		}

	}



	printMemory();

}



//���Ͽ� �� �����Է�

void writeRunFile() {

	char file_name[20];

	

	ofstream outfile;



	//�����̸� ����

	itoa(cnt_partition + 1, file_name, 10);

	strcat(file_name, "_partition.txt");



	outfile.open(file_name, ios::app);



	//outfile << memory[minIndex] << " ";

	outfile << " " << memory[minIndex];

	lastData = memory[minIndex];



	outfile.close();

	written[minIndex] = false;

}



//���� �޸𸮿� ���ִ� �� ���

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





//�����ϵ��� ȭ�鿡 ���

void printRun() {

	int i;

	ifstream file;

	int buf;

	char file_name[20];



	cout << "\n----------------------------------------------" << endl;



	for (i = 0; i <= cnt_partition; i++) {

		cout << i + 1 << "�� ����////" << endl;



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



//������ ���� ������ ó��

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

