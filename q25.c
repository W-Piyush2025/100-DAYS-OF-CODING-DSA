#include <stdio.h>
#include <stdlib.h>

// Define structure for node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key, i, count = 0;
    
    // Input number of nodes
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("0");
        return 0;
    }
    
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    
    // Create linked list dynamically
    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    
    // Input key
    scanf("%d", &key);
    
    // Count occurrences
    temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    
    // Output result
    printf("%d", count);
    
    return 0;
}