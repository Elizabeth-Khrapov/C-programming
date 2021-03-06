#ifndef __CHILD__
#define __CHILD__


typedef struct
{
	int	 id;
	int  age;
}Child;


void	readChild(FILE* fp, Child* pChild, int num);
void	getChildFromUser(Child* pChild, int id);
void	showChild(const Child* pChild);
void	writeChild(FILE* fp,const Child* pChild, int num);
int		findChildById(Child** pChildList, int count, int id);
void	birthday(Child* pChild);

int compareChildByID(const void* st1, const void* st2);

#endif
