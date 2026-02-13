#include <stdio.h>

void printSpiral(int r, int c, int matrix[r][c]) {
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    int dir = 0; // 0: right, 1: down, 2: left, 3: up

    while (top <= bottom && left <= right) {
        if (dir == 0) { // Right
            for (int i = left; i <= right; i++) printf("%d ", matrix[top][i]);
            top++;
        } else if (dir == 1) { // Down
            for (int i = top; i <= bottom; i++) printf("%d ", matrix[i][right]);
            right--;
        } else if (dir == 2) { // Left
            for (int i = right; i >= left; i--) printf("%d ", matrix[bottom][i]);
            bottom--;
        } else if (dir == 3) { // Up
            for (int i = bottom; i >= top; i--) printf("%d ", matrix[i][left]);
            left++;
        }
        dir = (dir + 1) % 4; // Cycle through 0, 1, 2, 3
    }
    printf("\n");
}

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return 1;

    int matrix[r][c];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);

    printSpiral(r, c, matrix);
    return 0;
}