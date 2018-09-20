/*
 * dlist.wrisigo.c
 *
 *  Created on: Sep 17, 2018
 *      Author: wlrisigo
 */


#include "dlist.wrisigo.h"
#include <stdio.h>
#include <stdlib.h>


int insertAtEnd(DListNode **theList, int data){


	DListNode *newNode = (DListNode *) malloc(sizeof(DListNode));

	DListNode *last = *theList;
	newNode->data = data;
	newNode->next = NULL;

	if(*theList == NULL){
		*theList = newNode;
		return(0);
	}
	while(last->next!=NULL){
		last= last->next;
	}
	last->next = newNode;
	newNode->prev = last;
	return(0);
}

int insertSorted(DListNode **theList, int data){
	DListNode *current;
	DListNode *newNode = (DListNode *) malloc(sizeof(DListNode));
	newNode->prev = newNode->next = NULL;
	newNode->data = data;
	//if list is null
	if( *theList == NULL){
		*theList = newNode;
	}
	//if data must be inserted as head
	else if((*theList)->data >= data){
		newNode->next = *theList;
		newNode->next->prev = newNode;
		*theList = newNode;
	}else{
			current= *theList;
		while(current->next != NULL && current->next->data < data){
			current = current->next;
		}

		newNode->next = current->next;

		if(current->next != NULL){
			newNode->next->prev = newNode;
		}

		current->next = newNode;
		newNode->prev = current;
		//newNode pointing to current
	}


	return(0);
}


void printListReverse(DListNode *theList){

	DListNode last;
	DListNode *current = theList;

	while( current->next != NULL ){
		current = current->next;
	}
	while(current != theList){
		printf(" %d ", current->data);
		current = current->prev;
	}
	printf(" %d ", current->data);
}

int isInList(DListNode *theList, int data){
	DListNode *current = theList;

	while(current != NULL && current->data != data ){
		current = current->next;
	}
	if(current == NULL){
		return(0);
	}
	else if(current->data == data){
		return(1);
	}
	else{
		return(999);
	}
}
int deleteFromList(DListNode **theList, int data){
	DListNode *temp = *theList;
	DListNode *current = *theList;
//	//is it in the list?
	if(isInList(*theList, data) == 0){
		return(1);
	}
while(current != NULL){
	if(current->data == data){
		temp = current->next;

		//delete the node
		if((*theList)->data == data)
			*theList = current->next;
		if(current->next != NULL)
			current->next->prev = current->prev;
		if(current->prev != NULL)
			current->prev->next = current->next;
		free(current);
		//Node deleted
		current = temp;
	}else{
		current = current->next;
	}
}

	return(0);
}

void printList(DListNode *theList){
	while(theList != NULL){
		printf(" %d ", theList->data);
		theList = theList->next;
	}
}

void test_1D() {

	DListNode *theList;
	int i;
	theList = NULL;
	for (i=1; i<=10; ++i) {
		insertAtEnd(&theList, i);
	}
	printList(theList);
	printf(" %s\n ", "");
	// should get 1 2 3 4 5 6 7 8 9 10
	for (i=20; i>=0; i=i-2) {

		if ( isInList(theList, i) ) {
			deleteFromList(&theList, i);
		} // 9-17-18 I forgot this bracket
	}
	printList(theList);
	// should get 1 3 5 7 9
}



void test_2D() {
	DListNode *theList;
	int i;
	theList = NULL;
	for (i=1; i<=10; ++i) {
		if (i%2 == 0)
			insertSorted(&theList, i);
		else
			insertSorted(&theList, 10-i);
	}
	printList(theList);
	// should get 1 2 3 4 5 6 7 8 9 10
	for (i=1; i<=9; ++i) {
		if (i%2 == 0)
			deleteFromList(&theList, i);
		else
			deleteFromList(&theList, 10-i);
	}
	printList(theList);
	// should get 10
}


void test_3D() {
	DListNode *theList;
	int i;
	theList = NULL;
	for (i=1; i<=10; ++i) {
		if (i < 5)
			insertSorted(&theList, 1); // 9-17-18 I changed this
		else
			insertSorted(&theList, 10);
	}
	printList(theList);
	printf(" %s\n ", "");
	// should get 1 1 1 1 10 10 10 10 10 10
	 deleteFromList(&theList, 1);
	 printf(" %s\n ", "");
	 printList(theList);
	 // should get 10 10 10 10 10 10
	 deleteFromList(&theList, 2);
	 printList(theList);
	 printf(" %s\n ", "");
	 // should get 10 10 10 10 10 10
	 deleteFromList(&theList, 10);
	 printList(theList);
	 printf(" %s\n ", "");
	 // should get nothing printed for the list
	}


	void test_4D() {
	 DListNode *theList; // 9-17-18 I forgot a semicolon here
	 int i;
	 theList = NULL;
	 for (i=1; i<=10; ++i) {
	 if (i%2 == 0)
	 insertSorted(&theList, i);
	 else
	 insertSorted(&theList, 10-i);
	 }
	 printList(theList);
	 // should get 1 2 3 4 5 6 7 8 9 10
	 printListReverse(theList);
	 // should get 10 9 8 7 6 5 4 3 2 1
	}



	int main(int argc, char *argv[])
	{
		test_4D();
		return(0);
	}


