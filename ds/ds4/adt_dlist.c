#include <stdlib.h> // malloc

#include "adt_dlist.h"

/* internal insert function
	inserts data into a new node
	return	1 if successful
			0 if memory overflow
*/
static int _insert( LIST *pList, NODE *pPre, void *dataInPtr);

/* internal delete function
	deletes data from a list and saves the (deleted) data to dataOut
*/
static void _delete( LIST *pList, NODE *pPre, NODE *pLoc, void **dataOutPtr);

/* internal search function
	searches list and passes back address of node
	containing target and its logical predecessor
	return	1 found
			0 not found
*/
static int _search( LIST *pList, NODE **pPre, NODE **pLoc, void *pArgu);


static int _insert(LIST* pList, NODE* pPre, void* dataInPtr) {
	// Data is not founded
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	if (!newNode) {
		free(newNode);
		return 0;
	}
	newNode->dataPtr = dataInPtr;

	// pPre == NULL
	if (!pPre) {
		// Insert a node in front of the list
		newNode->llink = NULL;
		newNode->rlink = pList->head;
		pList->head = newNode;

		// List is empty
		if (newNode->rlink == NULL) pList->rear = newNode;
		else newNode->rlink->llink = newNode;

	}
	else {
		if (pPre->rlink) {
			// Insert a node between two nodes
			newNode->rlink = pPre->rlink;
			pPre->rlink->llink = newNode;
		}
		else {
			// Insert a node at the end of the list
			newNode->rlink = NULL;
			pList->rear = newNode;
		}
		newNode->llink = pPre;
		pPre->rlink = newNode;
	}

	(pList->count)++;
}

static void _delete(LIST* pList, NODE* pPre, NODE* pLoc, void** dataOutPtr) {
	if (pLoc->llink) {
		pLoc->llink->rlink = pLoc->rlink;
	}
	else {
		pList->head = pLoc->rlink;
	}
	if (pLoc->rlink) {
		pLoc->rlink->llink = pLoc->llink;
	}
	else {
		pList->rear = pLoc->llink;
	}
	*dataOutPtr = pLoc->dataPtr;
	
	free(pLoc);
	(pList->count)--;
}

static int _search(LIST* pList, NODE** pPre, NODE** pLoc, void* pArgu) {
	int ret;
	*pPre = NULL;
	*pLoc = pList->head;

	while ((*pLoc) != NULL) {	//리스트의 끝이 아닐 때
		ret = (pList->compare)(pArgu, (*pLoc)->dataPtr);

		if (ret == 0) {	//찾음
			return 1;
		}
		else if (ret < 0) {
			break;
		}

		*pPre = *pLoc;
		*pLoc = (*pLoc)->rlink;
	}

	return 0;
}

LIST* createList(int (*compare)(const void*, const void*)) {
	LIST* list = (LIST*)malloc(sizeof(LIST));
	if (!list) return NULL; // Memory overflow
	list->count = 0;
	list->head = NULL;
	list->rear = NULL;
	list->compare = compare;

	return list;
}

void destroyList(LIST* pList, void (*callback)(void*)) {
	NODE* targetPtr = pList->head;
	NODE* temp = NULL;

	while (targetPtr) {
		callback(targetPtr->dataPtr);
		temp = targetPtr->rlink;
		free(targetPtr);
		targetPtr = temp;
	}
	free(pList);
}

int addNode(LIST* pList, void* dataInPtr, void (*callback)(const void*, const void*)) {
	NODE* pPre = NULL;
	NODE* pLoc = NULL;

	if (!_search(pList, &pPre, &pLoc, dataInPtr)) {
		if (!_insert(pList, pPre, dataInPtr))
			return 0;
		return 1;
	}
	else {
		// Data is founded
		callback(pLoc->dataPtr, dataInPtr);
		return 2;
	}
}

int removeNode(LIST* pList, void* keyPtr, void** dataOutPtr) {
	NODE* pPre = NULL;
	NODE* pLoc = NULL;

	int ret = _search(pList, &pPre, &pLoc, keyPtr);

	if (ret) {
		_delete(pList, pPre, pLoc, dataOutPtr);
		return 1;
	}
	else {
		return 0;
	}
}

int searchList(LIST* pList, void* pArgu, void** dataOutPtr) {
	NODE* pLoc = NULL;
	NODE* pPre = NULL;

	int ret = _search(pList, &pPre, &pLoc, pArgu);
	if (ret) {
		*dataOutPtr = pLoc->dataPtr;
		return 1;
	}
	else {
		return 0;
	}
}

int countList(LIST* pList) {
	return pList->count;
}

void traverseList(LIST* pList, void (*callback)(const void*)) {
	NODE* targetPtr = pList->head;

	while (targetPtr) {
		callback(targetPtr->dataPtr);
		targetPtr = targetPtr->rlink;
	}
}

void traverseListR(LIST* pList, void (*callback)(const void*)) {
	NODE* targetPtr = pList->rear;

	while (targetPtr) {
		callback(targetPtr->dataPtr);
		targetPtr = targetPtr->llink;
	}
}