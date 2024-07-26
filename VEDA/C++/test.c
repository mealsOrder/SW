#include<stdio.h>
// c언어 에서~
int main(){
    char x,y; // unsigned
    x = -128; // unsigned 이기 때문에 x에 128 저장
    y = -x;   // 

    if(x == y)printf("1\n");
    if((x-y) == 0)printf("2\n");
    if( (x+y) == 2*x)printf("3\n");
    if(x != -y)printf("4\n");

    int a=0,b=0,sum1=0,sum2=0;
    sum1 = a+++a+++a++;
    sum2 = ++b+ ++b+ ++b;
    printf("%d %d %d %d\n",a,b,sum1,sum2);
    return 0;
}