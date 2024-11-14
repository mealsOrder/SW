#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <iostream>
#include <cstring>
#include <cstdio>
#include <pthread.h>
#include <time.h>

class Circle
{
public:
    Circle();
    ~Circle();

    static Circle *create_instance(void);
    static Circle *get_instance(void);

private:
    void get_ins(void);
    static Circle* ins;
	char				iv_arr[MAX_BUFF_LEN];
	char				people_arr[MAX_BUFF_LEN];
	char				msg_app[MAX_BUFF_LEN];
	bool				con[MAX_CLIENT];
	INT32_N				num_obj;

    int					pInID;
	int					pOutID;

	// The number of passed people
	// 들어 가고 나간 사람의 수를 저장 하는 변수
	int					pIn;
	int					pOut;

	// Index of left/right line
	// 왼쪽 오른쪽 라인 인덱스
	// 내 생각인데 왼쪽으로 지나가면 이 인덱스를 증가시켜주고 해당 값을 어떤 배열의 인덱스로 사용 할 듯?
	int					lefLineIdx;
	int					rigLineIdx;
};