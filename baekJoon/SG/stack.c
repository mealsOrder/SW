#include<stdio.h>
#include<string.h>
int s[10001];

int top = -1;

void push(int x){
    s[++top] = x;
}
int empty(){
    if(top == -1) return 1;
    else return 0;
}
int pop(){ 
    if( empty() == 1) return -1;
    return s[top--];
}

int size(){
    return top + 1;
}

int toP(){
    if(top == -1) return -1;
    else return s[top];
}

int main(){
    int N;
    scanf("%d",&N);
    for(int i =0; i<N;i++){
        char op[10];
        scanf("%s",op);

        if(strcmp(op,"push") == 0){
            int n;
            scanf("%d",&n);
            push(n);
        }
        else if(strcmp(op,"pop") == 0){
            printf("%d\n",pop());
        }
        else if(strcmp(op,"size") == 0){
            printf("%d\n",size());
        }
        else if(strcmp(op,"empty") == 0){
            printf("%d\n",empty());
        }
        else if(strcmp(op,"top") == 0){
            printf("%d\n",toP());
        }
    }

    return 0;
}