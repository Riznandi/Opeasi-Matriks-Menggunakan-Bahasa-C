#include <stdio.h>

void inputMatrix(int row, int col, int matrix[row][col], char name) {
    printf("Masukkan elemen untuk matriks %c:\n", name);
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%c[%d][%d]: ", name, i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int row, int col, int matrix[row][col]) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int row, int col, int matrixA[row][col], int matrixB[row][col], int result[row][col]) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMatrices(int row, int col, int matrixA[row][col], int matrixB[row][col], int result[row][col]) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void multiplyMatrices(int rowA, int colA, int matrixA[rowA][colA], int rowB, int colB, int matrixB[rowB][colB], int result[rowA][colB]) {
    int i, j, k;
    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colB; j++) {
            result[i][j] = 0;
            for (k = 0; k < colA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    char repeat;
    char name[] = "Nama Anda";
    char npm[] = "NPM Anda";

    printf("Nama: %s\n", name);
    printf("NPM: %s\n", npm);

    do {
        int choice;
        printf("Pilih operasi matriks:\n1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            int row, col;
            printf("Masukkan jumlah baris matriks: ");
            scanf("%d", &row);
            printf("Masukkan jumlah kolom matriks: ");
            scanf("%d", &col);

            int matrixA[row][col], matrixB[row][col], result[row][col];

            inputMatrix(row, col, matrixA, 'A');
            inputMatrix(row, col, matrixB, 'B');

            if (choice == 1) {
                addMatrices(row, col, matrixA, matrixB, result);
                printf("Hasil penjumlahan matriks:\n");
            } else {
                subtractMatrices(row, col, matrixA, matrixB, result);
                printf("Hasil pengurangan matriks:\n");
            }

            printMatrix(row, col, result);

        } else if (choice == 3) {
            int rowA, colA, rowB, colB;
            printf("Masukkan jumlah baris matriks A: ");
            scanf("%d", &rowA);
            printf("Masukkan jumlah kolom matriks A: ");
            scanf("%d", &colA);
            printf("Masukkan jumlah baris matriks B: ");
            scanf("%d", &rowB);
            printf("Masukkan jumlah kolom matriks B: ");
            scanf("%d", &colB);

            if (colA != rowB) {
                printf("Matriks tidak dapat dikalikan. Kolom matriks A harus sama dengan baris matriks B.\n");
            } else {
                int matrixA[rowA][colA], matrixB[rowB][colB], result[rowA][colB];

                inputMatrix(rowA, colA, matrixA, 'A');
                inputMatrix(rowB, colB, matrixB, 'B');

                multiplyMatrices(rowA, colA, matrixA, rowB, colB, matrixB, result);

                printf("Hasil perkalian matriks:\n");
                printMatrix(rowA, colB, result);
            }
        } else {
            printf("Pilihan tidak valid.\n");
        }

        printf("Apakah Anda ingin melakukan perhitungan lagi? (y/n): ");
        scanf(" %c", &repeat);
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
