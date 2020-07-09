#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "City.h"
#include "Kindergarten.h"
#include "General.h"

void readCity(City* pCity , int chooseWhichFile)
{
	if (pCity->pGardenList != NULL) {
		releaseCity(pCity);
		pCity->count = 0;
	}
	pCity->pGardenList = readAllGardensFromFile(DATA_FILE, &pCity->count , chooseWhichFile);

	if (pCity->pGardenList == NULL)
		printf("Error reading city information\n");
}

void	showCityGardens(City* pCity)
{
	showAllGardens(pCity->pGardenList, pCity->count);
}

void	showSpecificGardenInCity(City* pCity)
{
	showGardenMenu(pCity->pGardenList, pCity->count);
}

void saveCity(City* pCity , int chooseWhichFile)
{
	writeGardensToFile(pCity->pGardenList, pCity->count, DATA_FILE , chooseWhichFile);
}

void cityAddGarden(City* pCity)
{
	pCity->pGardenList = addGarden(pCity->pGardenList, &pCity->count);
	if (pCity->pGardenList == NULL)//Allocation error
		printf("Error adding kindergarten\n");
}

void	addChildToSpecificGardenInCity(City* pCity)
{
	addChildToGarden(pCity->pGardenList, pCity->count);
}

void	birthdayToChild(City* pCity)
{
	handleBirthdayToChild(pCity->pGardenList, pCity->count);
}

int	countChova(City* pCity)
{
	int i;
	int count = 0;
	for (i = 0; i < pCity->count; i++)
	{
		if (pCity->pGardenList[i]->type == Chova)
			count += pCity->pGardenList[i]->childCount;
	}
	return count;
}
void sortKindergartenByName(City* pCity) 
{
	insertionSort(pCity->pGardenList, pCity->count, sizeof(Garden*),compareKindergartenByName);
}
void sortKindergartenByTypeAndnumber(City* pCity)
{
	insertionSort(pCity->pGardenList, pCity->count,sizeof(Garden*), compareKindergartenByTypeAndChildCount);
}
void sortChildrenByID(City* pCity) 
{
	sortChildByID(pCity->pGardenList, pCity->count);
}
void	releaseCity(City* pCity)
{
	release(pCity->pGardenList, pCity->count);
}
