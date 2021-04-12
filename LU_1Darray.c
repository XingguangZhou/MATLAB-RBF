#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void AllocateMatrix(double** matrix, int row, int col)
{
  *matrix = (double*)malloc(sizeof(double)* row * col);
  // memset the allocated memory to zero.
  memset(*matrix, 0, sizeof(double)*row*col);
}

void FreeMatrix(double* matrix)
{
  free(matrix);
  matrix = NULL;
}

void PrintMatrix(double* matrix, int row, int col)
{
  int i, j;
  for (i = 0; i < row; i++){
    for (j = 0; j < col; j++){
      printf("%.4f\t", matrix[i * row + j]);
    }
    printf("\n");
  }
}

void LU(double *matrix, double *L, double *U, int row, int col)
{
  int i, j, k;
  double sum = 0.0;
  // first frame
  for (i = 0; i < 1; i++){
    for (j = 0; j < col; j++){
      U[i*row + j] = matrix[i*row + j];
    }
  }
  // second frame
  for (i = 0; i < row; i++){
    for (j = 0; j < 1; j++){
      L[i*row + j] = matrix[i*row + j] / matrix[j*row + j];
    }
  }
  // the other frames
  for (i = 1; i < row; i++){
    for (j = i; j < col; j++){
      sum = 0.0;
      for (k = 0; k < i; k++){
        sum = sum + U[k*row + j] * L[i*row + k];
      }
      U[i*row + j] = matrix[i*row + j] - sum;
      sum = 0.0;
      for (k = 0; k < j; k++){
        sum = sum + U[k*row + i] * L[j*row + k];
      }
      L[j*row + i] = (matrix[j*row + i] - sum) / U[i*row + i];
    }
  }
}


int main(void)
{
  int row = 3;
  int col = 3;

  double *matrix = NULL;
  double *L = NULL;
  double *U = NULL;

  AllocateMatrix(&matrix, row, col);
  AllocateMatrix(&L, row, col);
  AllocateMatrix(&U, row, col);
  
  matrix[0] = 2; matrix[1] = 2; matrix[2] = 2;
  matrix[3] = 4; matrix[4] = 7; matrix[5] = 7;
  matrix[6] = 6; matrix[7] = 18; matrix[8] = 22;

  LU(matrix, L, U, row, col);

  // Print the Matrix
  PrintMatrix(matrix, row, col);
  printf("**********************\n");
  // Print the L
  PrintMatrix(L, row, col);
  printf("**********************\n");
  // Print the U
  PrintMatrix(U, row, col);

  FreeMatrix(matrix);
  FreeMatrix(L);
  FreeMatrix(U);
  return 0;
}
