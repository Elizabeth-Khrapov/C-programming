#ifndef NUMBERGAME_H_
#define NUMBERGAME_H_

void messTheMat(int* mat  , int row,int col);
void fillMat(int* mat  , int row,int col);
int checkIndex(int* mat, int row, int col, int x);
int startGame(int* mat, int row, int col);
void youWin();
int findRowX(int* mat, int row, int col, int x);
int findColX(int* mat, int row, int col, int x);
int checkIfWin(int* mat, int row, int col);
int numberGameMain();


#endif /* NUMBERGAME_H_*/
