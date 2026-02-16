#include <stdio.h>

int main() {
    int n, i, j, count;

    // 1. Get array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int visited[n];

    // 2. Get array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; // Initialize visited tracker to 0
    }

    printf("\nFrequency of elements:\n");

    // 3. Logic to count frequency
    for (i = 0; i < n; i++) {
        if (visited[i] == 1) {
            continue; // Skip if this element was already counted
        }

        count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = 1; // Mark as visited
                count++;
            }
        }
        printf("%d occurs %d times\n", arr[i], count);
    }

    return 0;
}