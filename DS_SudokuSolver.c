#include <stdio.h>

#define N 9

// Function to print the Sudoku board
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            printf("%d ", grid[row][col]);
        printf("\n");
    }
}

// Function to check if it's safe to place a number in a particular row, column, and 3x3 box
int isSafe(int grid[N][N], int row, int col, int num) {
    // Check if num is not in current row, column and 3x3 box
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return 0;
    }
//fhf
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return 0;
        }
    }
    return 1;
}

// Function to find an empty location in the grid (returns 1 if found, 0 if not)
int findEmptyLocation(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0)
                return 1;
        }
    }
    return 0;
}

// Recursive function to solve the Sudoku puzzle
int solveSudoku(int grid[N][N]) {
    int row, col;

    // If no empty space is left, puzzle is solved
    if (!findEmptyLocation(grid, &row, &col))
        return 1;

    // Try numbers 1 to 9 in the empty space
    for (int num = 1; num <= 9; num++) {
        // Check if placing num in grid[row][col] is valid
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num; // Place num

            // Recursively try to fill the next cell
            if (solveSudoku(grid))
                return 1;

            // If placing num leads to a solution, continue; otherwise, backtrack
            grid[row][col] = 0; // Reset cell to empty (backtrack)
        }
    }
    return 0; // Trigger backtracking
}

// Example Sudoku puzzle
int main() {
    //Declaring the Grid
    int grid[N][N];

    //Taking Input of Grid From the User
    printf("Enter the Grid : \n");
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d",&grid[i][j]);
        }
    }
    
    printf("\n\nThe entered Sudoku Grid is : \n");
    for(int i =0;i<9;i++){
        for(int j =0;j<9;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    
    if (solveSudoku(grid) == 1){
        printf("The Solution of the entered Sudoku Grid is : \n");
        printGrid(grid);
    }
    else
        printf("No solution exists!");

    return 0;
}
