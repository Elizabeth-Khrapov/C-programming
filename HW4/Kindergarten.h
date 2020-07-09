#ifndef __KINDERGARTEN__
#define __KINDERGARTEN__

#include "Child.h"

typedef enum
{
	Chova,
	TromChova,
	TromTromChova,
	NofTypes
} GardenType;

const char* GardenTypeName[NofTypes];

typedef struct
{
	char* name;
	GardenType  type;
	Child** childPtrArr;
	int		childCount;
}Garden;


Garden**	readAllGardensFromFile(char* fileName, int* pGardenCount, int num);
void	readGarden(FILE* fp, Garden* pGarden, int num);
GardenType	getTypeOption();

void	showAllGardens(Garden** pGardenList, int count);
void	showGarden(const Garden* pGarden);

void	writeGardensToFile(Garden** pGardenList, int gardenCount, char* fileName, int num);
void	writeGarden(FILE* fp,const Garden* pGarden, int num);


void	addChildToGarden(Garden** pGardenList, int gardenCount);
Garden**	addGarden(Garden** pGardenList, int* pGardenCount);

void	showGardenMenu(Garden** pGardenList, int count);
Garden*	getGardenAskForName(Garden** pGardenList, int count);

Garden*	findGardenByName(Garden** pGardenList, int count,const char* name);

Child*	getChildAskForId(Garden* pGarden);

void	getGardenFromUser(Garden* pGarden, Garden** pGardenList, int count);
void	getChildCheckIdFromUser(Child* pChild,const Garden* pGarden);

void	handleBirthdayToChild(Garden** pGardenList, int count);

void	release(Garden** pGardenList, int count);

int conpareByGardenName(const void* st1, const void* st2);
int conpareByGardenType(const void* st1, const void* st2);
int conpareByNumberOfChildren(const void* st1, const void* st2);
void sortGardenByID(Garden* pGarden);






#endif
