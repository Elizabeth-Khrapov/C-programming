#ifndef __CITY__
#define __CITY__

#include "Kindergarten.h"

#define DATA_FILE "DataFile.txt"

typedef struct
{
	Garden** pGardenList;
	int count;
}City;


void readCity(City* pCity, int chooseWhichFile);
void	showCityGardens(City* pCity);
void	showSpecificGardenInCity(City* pCity);
void saveCity(City* pCity, int chooseWhichFile);
void	cityAddGarden(City* pCity);
void	addChildToSpecificGardenInCity(City* pCity);
void	birthdayToChild(City* pCity);
int		countChova(City* pCity);
void sortKindergartenByName(City* pCity);
void sortKindergartenByTypeAndnumber(City* pCity);
void sortChildrenByID(City* pCity);
void	releaseCity(City* pCity);

#endif
