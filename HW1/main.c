#include <stdio.h>
#include <stdlib.h>
#include "numberGame.h"
#include "picture.h"

int main() {
	char choose;
	int goOut = 1;
do
{
	printf("Please choose one of the following options\nP/p - Picture Manipulation\nN/n - Number Game\nE/e - Quit ");
	scanf("%c", &choose);
	switch(choose)
	{
	case 'p':
	case 'P':
		pictureMain();
		break;
	case 'n':
	case 'N':
		numberGameMain();
		break;
	case 'e':
	case 'E':
		printf("Bye Bye !!!! ");
		goOut = 0;
		break;
	default :
	printf("Wrong number!\n");
	break;
	}
	getchar();
} while(goOut);

return 0 ;
}


