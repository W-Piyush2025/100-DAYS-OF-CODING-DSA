#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Helper function to compare elements for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;

    // Input the size of the array
    if (scanf("%d", &n) != 1 || n < 2) {
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    
    // Input the n space-separated integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array to use the two-pointer technique
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int min_sum = INT_MAX;
    int first_element, second_element;

    // Use two pointers to find the sum closest to zero
    while (left < right) {
        int current_sum = arr[left] + arr[right];

        // Update the result if the current sum is closer to zero
        if (abs(current_sum) < abs(min_sum)) {
            min_sum = current_sum;
            first_element = arr[left];
            second_element = arr[right];
        }

        // If sum is negative, we need a larger value (move left pointer)
        if (current_sum < 0) {
            left++;
        } 
        // If sum is positive, we need a smaller value (move right pointer)
        else if (current_sum > 0) {
            right--;
        } 
        // If sum is exactly zero, it's the closest possible
        else {
            break;
        }
    }

    // Output the pair of elements
    printf("%d %d\n", first_element, second_element);

    free(arr);
    return 0;
}