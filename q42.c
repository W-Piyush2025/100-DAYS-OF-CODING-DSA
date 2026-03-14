#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);      // push queue elements into stack
    }

    for(i = 0; i < n; i++) {
        printf("%d ", pop());   // pop from stack gives reversed order
    }

    return 0;
}