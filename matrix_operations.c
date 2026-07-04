/*
 * Project     : CodeAlpha_MatrixOperations
 * Author      : Kavya Agarwal
 * Description : Performs Matrix Addition, Matrix Multiplication and
 *               Matrix Transpose using functions and 2D arrays.
 * Internship  : CodeAlpha - C Programming Internship (Task 2)
 */

#include <stdio.h>

#define MAX 10

// Function prototypes
void inputMatrix(int mat[MAX][MAX], int rows, int cols, const char *name);
void displayMatrix(int mat[MAX][MAX], int rows, int cols, const char *name);
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX],
                       int r1, int c1, int r2, int c2);
void transposeMatrix(int mat[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int matA[MAX][MAX], matB[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    printf("=====================================\n");
    printf("        MATRIX OPERATIONS PROGRAM\n");
    printf("=====================================\n");

    do {
        printf("\nMenu:\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- Matrix Addition ---\n");
                printf("Enter rows and columns for both matrices (must match): ");
                scanf("%d %d", &rowsA, &colsA);
                rowsB = rowsA;
                colsB = colsA;

                inputMatrix(matA, rowsA, colsA, "Matrix A");
                inputMatrix(matB, rowsB, colsB, "Matrix B");

                addMatrices(matA, matB, result, rowsA, colsA);

                displayMatrix(matA, rowsA, colsA, "Matrix A");
                displayMatrix(matB, rowsB, colsB, "Matrix B");
                displayMatrix(result, rowsA, colsA, "Sum (A + B)");
                break;

            case 2:
                printf("\n--- Matrix Multiplication ---\n");
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d %d", &rowsA, &colsA);
                printf("Enter rows and columns of Matrix B: ");
                scanf("%d %d", &rowsB, &colsB);

                if (colsA != rowsB) {
                    printf("Error: Number of columns of A must equal number of rows of B!\n");
                    break;
                }

                inputMatrix(matA, rowsA, colsA, "Matrix A");
                inputMatrix(matB, rowsB, colsB, "Matrix B");

                multiplyMatrices(matA, matB, result, rowsA, colsA, rowsB, colsB);

                displayMatrix(matA, rowsA, colsA, "Matrix A");
                displayMatrix(matB, rowsB, colsB, "Matrix B");
                displayMatrix(result, rowsA, colsB, "Product (A x B)");
                break;

            case 3:
                printf("\n--- Matrix Transpose ---\n");
                printf("Enter rows and columns of the matrix: ");
                scanf("%d %d", &rowsA, &colsA);

                inputMatrix(matA, rowsA, colsA, "Matrix");
                transposeMatrix(matA, result, rowsA, colsA);

                displayMatrix(matA, rowsA, colsA, "Original Matrix");
                displayMatrix(result, colsA, rowsA, "Transposed Matrix");
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

// Takes matrix input from the user
void inputMatrix(int mat[MAX][MAX], int rows, int cols, const char *name) {
    printf("Enter elements of %s (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Displays a matrix in a readable grid format
void displayMatrix(int mat[MAX][MAX], int rows, int cols, const char *name) {
    printf("\n%s:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%6d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Adds two matrices of the same dimensions
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

// Multiplies matrix a (r1 x c1) with matrix b (r2 x c2), where c1 == r2
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX],
                       int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Produces the transpose of a matrix
void transposeMatrix(int mat[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = mat[i][j];
}
