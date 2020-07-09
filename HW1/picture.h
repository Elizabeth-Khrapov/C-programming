#ifndef PICTURE_H_
#define PICTURE_H_


#define RAND_MAX 51
#define RAND_MIN 0
#define MATRIX_SIZE 4


void swap(int* a, int* b);
int pictureMain();
int* randomMat(int* mat, int sizeMat);
void printMat(int* mat , int row , int col);
void printMatAfter(int* mat , int sizeMat);
void nintyDegreeClockwise(int* mat, int sizeMat);
void nintyDegreeCounterClockwise(int* mat, int sizeMat);
void flipHorizontal(int* mat , int sizeMat);
void flipVertical(int* mat , int sizeMat);
#endif /* PICTURE_H_ */
