#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int uniqueIdx = 0; 
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[uniqueIdx]) {
            uniqueIdx++;
            arr[uniqueIdx] = arr[i];
        }
    }

    for (int i = 0; i <= uniqueIdx; i++) {
        printf("%d%s", arr[i], (i == uniqueIdx) ? "" : " ");
    }
    printf("\n");

    return 0;
}