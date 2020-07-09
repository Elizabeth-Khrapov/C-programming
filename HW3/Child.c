#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Child.h"
#include "General.h"
#include "Kindergarten.h"


/**************************************************/
/*             Read a Child from a file           */
/**************************************************/
void readChild(FILE* fp, Child* pChild)
{
	//Child ID
	fscanf(fp, "%d", &pChild->id);
	fscanf(fp, "%d", &pChild->age);
}


/**************************************************/
/*            show a Child				           */
/**************************************************/
void showChild(const Child* pChild)
{
	printf("\nID:%d  ", pChild->id);
	printf("Age:%d  ", pChild->age);
}


/**************************************************/
void getChildFromUser(Child* pChild, int id)
/**************************************************/
/**************************************************/
{
	pChild->id = id;
	
	puts("\nAge:\t");
	scanf("%d", &pChild->age);
}


/**************************************************/
/*Write a Child to the open file				*/
/**************************************************/
void writeChild(FILE* fp,const Child* pChild)
{
	fprintf(fp,"%d %d\n",pChild->id, pChild->age);
}

//linear search
Child*	findChildById(Child** pChildList, int count, int id)
{
	Child tempChild = {id,NULL};
	Child* found;
	Child* tempC = &tempChild;
		qsort(pChildList, count, sizeof(Child*), compareChildById);
		found = (Child*)bsearch(&tempC, pChildList, count, sizeof(Child*), compareChildById);
			return found;
}

void birthday(Child* pChild)
{
	pChild->age++;
}


//void	releaseChild(Child* pChild)
//{
//	//nothing to release
//}
