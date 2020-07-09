#ifndef __PROTOTYPE__
#define __PROTOTYPE__
#include "Child.h"
#include "Kindergarten.h"

typedef enum
{
	EXIT,
	READ_CITY,
	SHOW_CITY,
	SHOW_GARDEN,
	WRITE_CITY,
	ADD_GARDEN,
	ADD_CHILD,
	CHILD_BIRTHDAY,
	COUNT_GRADUATE,
	SORT_BY_NAME,
	SORT_BY_TYPE_NUMBER,
	SORT_CHILD,
	LINKED_LIST,
	NofOptions
} MenuOptions;

int		menu();
char*	getStrExactLength(char* inpStr);
int		checkAllocation(const void* p);
void insertionSort(void* arr, int num, int size, int compare(const void*, const void*));
int compareKindergartenByTypeAndChildCount(const void* garden1, const void* garden2);
int compareChildById(const void* child1,const void* child2);
int compareKindergartenByName(const void* garden1,const void* garden2);




#endif
