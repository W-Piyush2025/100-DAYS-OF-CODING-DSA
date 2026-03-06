#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int evaluate(char postfix[]) {
    int i = 0;

    while (postfix[i] != '\0') {

        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        }
        else if (postfix[i] == '+' || postfix[i] == '-' ||
                 postfix[i] == '*' || postfix[i] == '/') {

            int b = pop();
            int a = pop();

            switch(postfix[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }

        i++;
    }

    return pop();
}

int main() {
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int result = evaluate(postfix);

    printf("Result = %d\n", result);

    return 0;
}