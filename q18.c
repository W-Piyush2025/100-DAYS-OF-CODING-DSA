#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 2;

    k = k % n; // Handle cases where k > n

    // Step 1: Reverse whole array -> {5, 4, 3, 2, 1}
    reverse(arr, 0, n - 1);
    
    // Step 2: Reverse first k elements -> {4, 5, 3, 2, 1}
    reverse(arr, 0, k - 1);
    
    // Step 3: Reverse remaining n-k elements -> {4, 5, 1, 2, 3}
    reverse(arr, k, n - 1);

    printf("Rotated array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}