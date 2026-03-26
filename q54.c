#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];
            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

// Zigzag Traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Node* s1[100], *s2[100];
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while (top1 != -1 || top2 != -1) {

        // Left to Right
        while (top1 != -1) {
            struct Node* temp = s1[top1--];
            printf("%d ", temp->data);

            if (temp->left)
                s2[++top2] = temp->left;
            if (temp->right)
                s2[++top2] = temp->right;
        }

        // Right to Left
        while (top2 != -1) {
            struct Node* temp = s2[top2--];
            printf("%d ", temp->data);

            if (temp->right)
                s1[++top1] = temp->right;
            if (temp->left)
                s1[++top1] = temp->left;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}