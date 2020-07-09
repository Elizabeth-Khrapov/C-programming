#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "picture.h"


int* randomMat(int* mat, int sizeMat) {
	srand(time(NULL));
	for (int i = 0; i < sizeMat * sizeMat; ++i, ++mat) {
		*mat = RAND_MIN + (rand() % (RAND_MAX - RAND_MIN));
	}
	return mat;
}
void matrixTranspose(int* mat , int sizeMat) {
for (int i = 0; i < sizeMat; i++)
	{
		for (int j = i; j < sizeMat; j++)
		{
			swap(mat + sizeMat * i + j, mat + sizeMat * j + i);
		}
}
}
void nintyDegreeCounterClockwise(int* mat, int sizeMat) {
	matrixTranspose(mat, sizeMat);
	flipHorizontal(mat, sizeMat);
}
void nintyDegreeClockwise(int* mat, int sizeMat) {
	matrixTranspose(mat, sizeMat);
	flipVertical(mat, sizeMat);
}
void flipHorizontal(int* mat, int sizeMat) {
	for (int x = 0; x < (sizeMat / 2); ++x) {
		for (int y = 0; y < sizeMat; ++y) {
			swap(mat + sizeMat * x + y, mat + sizeMat * (sizeMat-1 - x) + y);
		}
	}
	printMatAfter(mat, sizeMat);
}
void flipVertical(int* mat, int sizeMat) {
	for (int x = 0; x < sizeMat; ++x) {
		for (int y = 0; y < sizeMat/2 ; ++y) {
			swap(mat + sizeMat * x + y, mat + sizeMat * x + (sizeMat-1 - y));
		}
	}
	printMatAfter(mat, sizeMat);

}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void printMat(int* mat, int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%3d ", *mat);
			++mat;
		}
		printf("\n");
	}
	printf("\n");
}
void printMatAfter(int* mat, int sizeMat) {
	printf("--------- picture after manipulation ---------\n");
	printMat(mat, sizeMat,sizeMat);
}

int chooseManu(int* mat, int sizeMat) {
	int pChoose;
	printf(
			"Please choose one of the following options\n1 - 90 degree clockwise\n2 - 90 degree counter clockwise\n3 - Flip Horizontal\n4 - Flip Vertical\n-1 - Quit\n");
	scanf("%d", &pChoose);
	switch (pChoose) {
	case 1:
		nintyDegreeClockwise(mat, sizeMat);
		break;
	case 2:
		nintyDegreeCounterClockwise(mat, sizeMat);
		break;
	case 3:
		flipHorizontal(mat, sizeMat);
		break;
	case 4:
		flipVertical(mat, sizeMat);
		break;
		printf("Wrong value!\n Please try again!");
		break;
	}
	return pChoose;
}
int pictureMain() {
	srand(time(0));
	int mat[MATRIX_SIZE][MATRIX_SIZE];
	int *pMat = &mat[0][0];
	randomMat(pMat, MATRIX_SIZE);
	printMat(pMat, MATRIX_SIZE , MATRIX_SIZE);
	do {

	} while (chooseManu(pMat, MATRIX_SIZE) != -1);
	return 0;
}


