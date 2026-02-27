#include <stdio.h>
#include <stdlib.h>

// Define Node
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL)
        return newNode;
    
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNode;
    return head;
}

// Find intersection by value
int findIntersection(struct Node* head1, struct Node* head2) {
    while (head1 != NULL) {
        struct Node* temp = head2;
        while (temp != NULL) {
            if (head1->data == temp->data)
                return head1->data;
            temp = temp->next;
        }
        head1 = head1->next;
    }
    return -1;
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}