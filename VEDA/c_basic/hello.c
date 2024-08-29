#include<stdio.h>
#include<stdlib.h>
int sum(){
    static int count = 1;
    int s = 0;

    s+=count;
    count++;


    return s;

}
int main(){

    for(int i=0;i<10;i++){
        printf("%d ",sum());
    }
    return 0;
}