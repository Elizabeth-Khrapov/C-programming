#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Kindergarten.h"
#include "Child.h"
#include "City.h"

int chooseWhichFile() {
	int x;
	printf("Enter 1 for Binary file or 0 for text File");
	scanf("%d", &x);
	return x;
}


int main()
{
	City utz = { NULL,0 };
	int uReq, chooseFile;
	chooseFile = chooseWhichFile();
	if (chooseFile)
	{

	}

	//first time read
	readCity(&utz , chooseFile);
	do
	{
		uReq = menu();
		switch (uReq)
		{
		case  READ_CITY:
			readCity(&utz , chooseFile);
			break;

		case  SHOW_CITY:
			showCityGardens(&utz);
			break;

		case  SHOW_GARDEN:
			showSpecificGardenInCity(&utz);
			break;

		case  WRITE_CITY:
			saveCity(&utz, chooseFile);
			break;

		case  ADD_GARDEN:
			cityAddGarden(&utz);
			break;

		case  ADD_CHILD:
			addChildToSpecificGardenInCity(&utz);
			break;

		case  CHILD_BIRTHDAY:
			birthdayToChild(&utz);
			break;

		case COUNT_GRADUATE:
			printf("There are %d children going to school next year\n",countChova(&utz));
			break;

		case SORT_BY_NAME:
			sortKindergartenByName(&utz);
			break;

case SORT_BY_TYPE_NUMBER:
	 sortKindergartenByTypeAndnumber(&utz);
	 break;

case SORT_CHILD:
	sortChildrenByID(&utz);
	break;
case LINKED_LIST:
	break;
		}
	}while (uReq!=EXIT);
	
	releaseCity(&utz);//free all allocations
	
	return EXIT_SUCCESS;
}

