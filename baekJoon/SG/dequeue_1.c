#include <stdio.h>
#include <string.h>

int d[10001];
int begin = 0, end = 0;

void push_front(int x){
    if (begin == 0){ 
        for (int i = end; i > begin; i--){
            d[i] = d[i - 1];
        }
        end++;
    }
    d[begin] = x;
}

void push_back(int x){
    d[end++] = x;
}

int empty(){
    return (begin == end) ? 1 : 0;
}

int pop_front(){
    if (empty()) return -1;
    return d[begin++];
}

int pop_back(){
    if (empty()) return -1;
    return d[--end];
}

int size(){
    return end - begin;
}

int front(){
    if (empty()) return -1;
    return d[begin];
}

int back(){
    if (empty()) return -1;
    return d[end - 1];
}

int main(){
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        char op[15];
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0){
            int n;
            scanf("%d", &n);
            push_front(n);
        }else if (strcmp(op, "push_back") == 0){
            int n;
            scanf("%d", &n);
            push_back(n);
        }else if (strcmp(op, "pop_front") == 0){
            printf("%d\n", pop_front());
        }else if (strcmp(op, "pop_back") == 0){
            printf("%d\n", pop_back());
        }else if (strcmp(op, "size") == 0){
            printf("%d\n", size());
        }else if (strcmp(op, "empty") == 0){
            printf("%d\n", empty());
        }else if (strcmp(op, "front") == 0){
            printf("%d\n", front());
        }else if (strcmp(op, "back") == 0){
            printf("%d\n", back());
        }
    }

    return 0;
}