#include <stdio.h>

int main() {
    int m, n;

    // 1. Read the dimensions (rows and columns)
    if (scanf("%d %d", &m, &n) != 2) {
        return 1; // Exit if input is invalid
    }

    // Declare matrices using Variable Length Arrays (VLA)
    int matrix1[m][n];
    int matrix2[m][n];
    int sum[m][n];

    // 2. Read the elements of the first matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // 3. Read the elements of the second matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // 4. Calculate the sum and print the result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Addition: Result[i][j] = Matrix1[i][j] + Matrix2[i][j]
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
            
            // Print the element followed by a space
            printf("%d", sum[i][j]);
            
            // Add a space between elements, but not after the last element in a row
            if (j < n - 1) {
                printf(" ");
            }
        }
        // New line after each row
        printf("\n");
    }

    return 0;
}