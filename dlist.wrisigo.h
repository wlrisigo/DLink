/*
 * dlist.wrisigo.h
 *
 *  Created on: Sep 17, 2018
 *      Author: wlrisigo
 */

#ifndef NULL
#define NULL   ((void *) 0)

#include <stdio.h>

typedef struct dlistStruct {
 int data;
 struct dlistStruct *next;
 struct dlistStruct *prev;
} DListNode;


void test_1D();
void test_2D();
void test_3D();
void test_4D();
void printList(DListNode *theList); //DONE
/* print the list items from head to tail */
void printListReverse(DListNode *theList); //DONE
/* print the list items from tail to head */
int insertAtEnd(DListNode **theList, int data); //DONE
/* return zero if successful */
int insertSorted(DListNode **theList, int data);
/* return zero if successful */
int isInList(DListNode *theList, int data);
/* return non-zero value if the value is in the list; otherwise return zero */
int deleteFromList(DListNode **theList, int data);
/* if the value isn't in the list, then do nothing and return non-zero value;
 otherwise delete all listnodes matching the data from the list and
 return zero */


#endif /* DLIST_WRISIGO_H_ */
