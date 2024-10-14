#include <stdio.h>

#define SIZE 5  

// function declarations

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE], char* label);

int main() {
    // make the matrices with values

    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int result[SIZE][SIZE]; // store operations

    // add the matrices

    addMatrices(m1, m2, result);
    printMatrix(result, "Sum of m1 and m2");

    // multiply the matrices

    multiplyMatrices(m1, m2, result);
    printMatrix(result, "Product of m1 and m2");

    // transpose the matrix m1

    transposeMatrix(m1, result);
    printMatrix(result, "Transpose of m1");

    return 0;
}

// function to add two matrices

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    printf("\nAdding matrices\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j]; 
        }
    }
}

// function to multiply two matrices

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    printf("\nMultiplying matrices\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0; // make result zero
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];  // matrix logic
            }
        }
    }
}

// transpose matrix

void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    printf("\nTransposing the matrix\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];  // change rows and columns
        }
    }
}

// print a matrix

void printMatrix(int matrix[SIZE][SIZE], char* label) {
    printf("\n%s:\n", label); 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", matrix[i][j]);  // print element
        }
        printf("\n");  
    }
    printf("\n");  
}
