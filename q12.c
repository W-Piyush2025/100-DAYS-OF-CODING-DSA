#include <stdio.h>

int main() {
    int m, n;

    // Input rows and columns
    if (scanf("%d %d", &m, &n) != 2) return 1;

    // Condition 1: Must be a square matrix
    if (m != n) {
        printf("The matrix is not symmetric.\n");
        return 0;
    }

    int matrix[m][n];

    // Input matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int isSymmetric = 1; // Assume symmetric until proven otherwise

    // Condition 2: Check if A[i][j] == A[j][i]
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) { // We only need to check one half of the matrix
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) break;
    }

    if (isSymmetric) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }

    return 0;
}