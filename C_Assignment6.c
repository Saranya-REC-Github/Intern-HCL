//Place N Cameras Without Conflict on Blocked Grid | HackerRank
#include <stdio.h>
#include <stdbool.h>
bool solve(int row, int N, int** grid, int* col, int* d1, int* d2) {
    if (row == N)
        return true;
    for (int c = 0; c < N; c++) {
        if (grid[row][c] == 0 &&
            !col[c] &&
            !d1[row - c + N - 1] &&
            !d2[row + c]) {
            col[c] = d1[row - c + N - 1] = d2[row + c] = 1;
            if (solve(row + 1, N, grid, col, d1, d2))
                return true;
            col[c] = d1[row - c + N - 1] = d2[row + c] = 0;
        }
    }
    return false;
}
bool canPlaceSecurityCameras(int N, int** grid) {
    int col[N];
    int d1[2*N];
    int d2[2*N];
    for(int i = 0; i < N; i++)
        col[i] = 0;
    for(int i = 0; i < 2*N; i++)
        d1[i] = d2[i] = 0;
    return solve(0, N, grid, col, d1, d2);
}
int main() {
    int N = 4;
    int arr[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    int* grid[4];
    for(int i = 0; i < N; i++)
        grid[i] = arr[i];
    if (canPlaceSecurityCameras(N, grid))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}
