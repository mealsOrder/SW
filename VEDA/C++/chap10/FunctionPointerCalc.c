#include <stdio.h>

/* 함수 포인터를 위한 선언 */
//float (*funcPtr)(int, int);
typedef float (*funcPtr)(int, int);

/* 함수의 선언 */
float plus(int op1, int op2);
float minus(int op1, int op2);
float multiply(int op1, int op2);
float divide(int op1, int op2); 

/* 메인 함수 */
int main( )
{
   int num1, num2;
   char op;
   float result;
   funcPtr calc; /* 함수 포인터의 변수 */
 /* 숫자와 연산자의 입력 */
   printf("Input the number1 : ");
   scanf("%d", &num1);
   printf("Input the number2 : ");
   scanf("%d", &num2);
   printf("Opeartor(+,-,*,/) : ");
   scanf("%*c%c", &op);

   /* 연산자에 따라서 계산 */   
   switch(op) {
   case '+':       // 덧셈 : 2개의 인자 전달
       calc = plus; 
       break;         
   case '-':       // 뺄셈
       calc = minus; 
       break; 
  case '*':      // 곱셈
       calc = multiply; 
       break;
  case '/':      // 나눗셈
       calc = divide; 
       break;
   };   
   result = calc(num1, num2);   
   /* 결과의 출력 */
   printf("%d %c %d = %.2f\n", 
               num1, op, num2, result);   
   return 0;
}

/* 덧셈 계산을 위한 함수 */
float plus(int op1, int op2)
{
   float num = op1 + op2;
   return num;
}

/* 뺄셈 계산을 위한 함수 */
float minus(int op1, int op2)
{
   float num = op1 - op2;
   return num;
}   

/* 곱셈 계산을 위한 함수 */
float multiply(int op1, int op2)
{
   float num = op1 * op2;
   return num;
}   

/* 나눗셈 계산을 위한 함수 */
float divide(int op1, int op2)
{
   float num = op1 / (float)op2;
   return num;
} 
