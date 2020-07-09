#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "General.h"


const char* optionStr[NofOptions] =
{
	"Exit","Read City information from file",
	"Show all Kindergartens","Show a specific Kindergarten",
	"Save City information to file","Add a Kindergarten",
	"Add a Child","Birthday to a Child",
	"Count Hova childres","sort Kindergartens by name",
	"sort Kindergartens by type and children numbers.","sort children in a kindergarten",
	"Kindergartens in Linked list"
};


/**************************************************/
int menu()
/**************************************************/
/**************************************************/
{
	int option,i;

	printf("\n==========================");
	printf("\nSelect:\n");
	for(i = 0 ; i < NofOptions; i++)
		printf("\n\t%d. %s.",i, optionStr[i]);
	printf("\n");
	scanf("%d", &option);
	return option;
}

char* getStrExactLength(char* inpStr)
{
	char* theStr = NULL;
	size_t len;

	len = strlen(inpStr) + 1;
	//allocate a place for the string in the right location in the array 
	theStr = (char*)malloc(len*sizeof(char));
	//Copy the string to the right location in the array 
	if (theStr != NULL)
		strcpy(theStr, inpStr);

	return theStr;
}

int checkAllocation(const void* p)
{
	if (!p)
	{
		printf("ERROR! Not enough memory!");
		return 0;
	}
	return 1;
}
void insertionSort(void* arr, int num, int size, int compare(const void*, const void*))
{
	char* i;
	char* j;
	char* key = (char*)malloc(size);

	for (i = (char*)arr + size; --num; i += size)
	{
		memcpy(key, i, size);
		for (j = i - size; j >= (char*)arr && compare(key, j) < 0; j -= size)
		{
			memmove(j + size, j, size);
		}
		memmove(j + size, key, size);
	}
	free(key);
}

int compareKindergartenByTypeAndChildCount(const void* garden1, const void* garden2)
{
	int differentType;
	const Garden* g1 = (const Garden*)garden1;
	const Garden* g2 = (const Garden*)garden2;
	differentType = (int)g1->type - (int)g2->type;
	if (!differentType)
	{
		return g1->childCount - g2->childCount;
	}
	return differentType;
}
int compareChildById(const void* child1,const void* child2)
{
Child* p1 = *(const Child**)child1;
Child* p2 = *(const Child**)child2;
return (p1->id - p2->id); 
}

int compareKindergartenByName(const void* garden1,const void* garden2)
{
	Garden* p1 = (const Garden*)garden1;
	Garden* p2 = (const Garden*)garden2;
	return strcmp(p1->name, p2->name);
}

