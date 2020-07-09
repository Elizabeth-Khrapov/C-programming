#ifndef __CITY__
#define __CITY__

#include "Kindergarten.h"


#define DATA_FILE "DataFile.txt"
#define BIN_FILE "DataFile.bin"
#include "Node.h"

typedef struct
{
	Garden** pGardenList;
	int count;
}City;


void	readCity(City* pCity, int num);
void	showCityGardens(City* pCity);
void	showSpecificGardenInCity(City* pCity);
void	saveCity(City* pCity, int num);
void	cityAddGarden(City* pCity);
void	addChildToSpecificGardenInCity(City* pCity);
void	birthdayToChild(City* pCity);
int		countChova(City* pCity);
void	releaseCity(City* pCity);

void sortGardenByName(City* pCity);
void sortGardenByTypeAndNumberOfChildren(City* pCity);
void sortChildrenByID(City* pCity);

LIST* createLinkedListForKindergartenType(City* pCity, int type);
void displayKindergartensForList(LIST list);
LIST* kindergartensLinkedList(City* pCity);


#endif
