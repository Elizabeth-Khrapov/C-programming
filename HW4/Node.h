/*
 * Node.h
 *
 *  Created on: Jan 2, 2019
 *      Author: lir
 */

#ifndef NODE_H_
#define NODE_H_
#include "Kindergarten.h"

typedef Garden DATA;

typedef struct node {
	DATA key;
	struct node* next;
} NODE;

typedef struct {
	NODE head;
} LIST;

int 	L_init(LIST* pList);
NODE* 	L_insert(NODE* pNode, DATA Value);
int 	L_delete(NODE* pNode);
int 	L_free(LIST* pList);
int 	L_printGardenList(LIST* pList);

#endif /* NODE_H_ */
