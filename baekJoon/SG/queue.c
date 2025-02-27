#include<stdio.h>
#include<string.h>

int q[10001];
int begin = 0, end = 0;

void push(int x){
    q[end++] = x;
}

int size(){
    return end - begin;
}

int empty(){
    if(begin == end) return 1;
    else return 0;
}

int front(){
    if(empty() == 1) return -1;
    else return q[begin];
}

int back(){
    if(empty() == 1) return -1;
    else return q[end-1];
}

int pop(){
    if(empty() == 1) return -1;
    return q[begin++];
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
        else if(strcmp(op,"front") == 0){
            printf("%d\n",front());
        }
        else if(strcmp(op,"back") == 0){
            printf("%d\n",back());
        }
    }

    return 0;
}