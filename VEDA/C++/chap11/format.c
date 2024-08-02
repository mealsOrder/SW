#include<stdio.h>
#include<windows.h>
int main(){
    int n;

    const char *format = "%d\n";

    // printf(format,123);
    // printf("\r%f",45.6);
    // printf("\r%s%n\n","Hello World",&n);
    // printf("Len : %d\n",n);
    int cnt = 0;
    while(1){
        if(cnt == 101) {
            printf("\nComplete!\n");
            break;
        }
        printf("\r%d%%",cnt);
        fflush(stdout);
        Sleep(100);
        cnt++;
    }
    
    return 0;
}