#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "picture.h"
#include "numberGame.h"
#define ROW 5
#define COL 3
#define SHUFFEL_COUNT 20
#define MAX ROW*COL

void fillMat(int* mat, int row, int col) {
	for (int i = 0; i < row * col; ++i) {
		*mat = i;
		++mat;
	}
}
void messTheMat(int* mat, int row, int col) {
	srand(time(NULL));
	for (int i = 0; i < SHUFFEL_COUNT; i++) {
		int index1 = RAND_MIN + (rand() % (MAX - RAND_MIN));
		int index2 = RAND_MIN + (rand() % (MAX - RAND_MIN));
		swap(mat + index1, mat + index2);
	}
}
int checkIfWin(int* mat, int row, int col) {
	printf("\n");
	for (int i = 0; i < row * col - 1; ++i, ++mat) {
		if (*mat != i + 1)
			return 0;
	}
	youWin();
	return 1;
}
int findColX(int* mat, int row, int col, int x) {
	for (int i = 0; i < col; ++i) {
		for (int j = 0; j < row; ++j) {
			if (*(mat + col * i + j) == x) {
				return j;
			}
		}
	}
	return -1;
}
int findRowX(int* mat, int row, int col, int x) {
	for (int i = 0; i < col; ++i) {
		for (int j = 0; j < row; ++j) {
			if (*(mat + col * i + j) == x) {
				return i;
			}
		}
	}
	return -1;
}
int checkIndex(int* mat, int row, int col, int x) {
	int pXCol = findColX(mat, row, col, x);
	int pXRow = findRowX(mat, row, col, x);
	int pZeroRow = findRowX(mat, row, col, 0);
	int pZeroCol = findColX(mat, row, col, 0);
	int* indexZero = mat + col * pZeroRow + pZeroCol;
	int* indexOfX = mat + col * pXRow + pXCol;
	if ((pXCol == pZeroCol)
			&& (*(indexZero - col) == x || *(indexZero + col) == x)) {
		swap(indexZero, indexOfX);
		return 1;
	}
	if ((pXRow == pZeroRow)
			&& (*(indexZero + 1) == x || *(indexZero - 1) == x)) {
		swap(indexZero, indexOfX);
		return 1;

	}
	printf("Invalid step!\n");
	return 0;
}
void youWin() {
	printf("You win! The game is over!\n\n\n ");
	exit(0);
}

int startGame(int* mat, int row, int col) {
	int x, check = 0, checkifWin = 0;
	checkifWin = checkIfWin(mat, row, col);
	while (checkifWin == 0 || check == 0) {
		printMat(mat, row, col);
		printf("\nYour step:");
		scanf("%d", &x);
		check = checkIndex(mat, row, col, x);
		checkifWin = checkIfWin(mat, row, col);
	}

	return 0;
}
int numberGameMain() {
	int mat[ROW][COL];
	int* pMat = &mat[0][0];
	fillMat(pMat, ROW, COL);
	messTheMat(pMat, ROW, COL);
	startGame(pMat, ROW, COL);
	return 0;
}

