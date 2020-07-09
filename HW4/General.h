#ifndef __PROTOTYPE__
#define __PROTOTYPE__

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
	SORT_GARDENS_BY_NAME,
	SORT_CHILDRENS_BY_ID,
	SORT_GARDENS_BY_TYPE_AND_NUMBER,
	CREATE_KINDERGARTENS_LINKED_LIST,
	NofOptions
} MenuOptions;


int		menu();
char*	getStrExactLength(char* inpStr);
int		checkAllocation(const void* p);
void insertionSort(void* arr, int size, int typeSize,
		int (*compare)(const void*,const void*));
void swap(void* a, void* b, int typeSize);

void Variadic_Function(char* str, int num, ...);




#endif
