#include "repository.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>

DynamicArray* createDynamicArray(int capacity)
{
	DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
	if (da == NULL)
		return NULL;

	da->capacity = capacity;
	da->length = 0;

	da->elems = (TElement**)malloc(capacity * sizeof(TElement*));
	if (da->elems == NULL)
		return NULL;

	return da;
}


void destroy(DynamicArray* arr)
{
	for (int i = 0; i < arr->length; i++) destroyMedicine(arr->elems[i]);
	free(arr->elems);
	free(arr);
}

void resize(DynamicArray* arr)
{   
	arr->capacity *= 1.5;
	TElement* tmp = (TElement**)realloc(arr->elems, arr->capacity * sizeof(TElement*));
	if (tmp != NULL) { arr->elems = tmp; }
	else printf("caca\n");
}

void add(DynamicArray* arr, TElement* t)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;
	if (arr->length == arr->capacity)
		resize(arr);
	arr->elems[arr->length] = t;
	arr->length++;
}


int getMedicine(DynamicArray* arr, char name[], double concentration)
{
	for (int i = 0; i < arr->length; i++)
		if (strcmp(name, arr->elems[i]->name) == 0 && concentration == arr->elems[i]->concentration)
			return i;
	return -1;
}

void updateMedicine(DynamicArray* arr, int position, int newQuantity)
{
	arr->elems[position]->quantity = newQuantity;
}

void deleteMedicine(DynamicArray* arr, int position)
{
	//medicine on pos position shall be deleted
	destroyMedicine(arr->elems[position]);
	for (int i = position; i < arr->length; i++)
		arr->elems[i] = arr->elems[i + 1];
	arr->length -= 1;
}

int stringMatch(Medicine* m, char str[])
{
	if (strlen(str) == 0)return 1;
	if (strstr(m->name, str) != NULL) return 1;
	return 0;
}

void swapElem(DynamicArray* arr, int i, int j)
{
	Medicine* aux = arr->elems[j];
	arr->elems[j] = arr->elems[i];
	arr->elems[i] = aux;

}

void sortAscendingByName(DynamicArray* arr)
{
	for (int i = 0; i < arr->length - 1; i++)
		for (int j = i + 1; j < arr->length; j++)
			if (strcmp(arr->elems[i]->name, arr->elems[j]->name) > 0)
				swapElem(arr, i, j);
}


UndoRedoRecord* createRecord(int capacity)
{
	UndoRedoRecord* r = (UndoRedoRecord*)malloc(sizeof(UndoRedoRecord));
	if (r == NULL)
		return NULL;
	r->capacity = capacity;
	r->length = 0;
	r->stages = (TUndo**)malloc(capacity * sizeof(TUndo*));
	return r;
}

void destroyUR(UndoRedoRecord* arr)
{
	for (int i = 0; i < arr->length; i++) destroy(arr->stages[i]);
	free(arr->stages);
	free(arr);
}

void resizeUR(UndoRedoRecord* arr)
{ 
	arr->capacity *= 1.5;
	arr->stages = (TUndo**)realloc(arr->stages, arr->capacity * sizeof(TUndo*));
	if (arr->stages == NULL) free(arr->stages);
}


TUndo* createCopy(TUndo *stage)
{
	DynamicArray* lastStage = createDynamicArray(stage->length + 1);
	for (int i = 0; i < stage->length; i++)
	{
		Medicine* elemToAdd = copyMedicine(stage->elems[i]);
		add(lastStage, elemToAdd); }
		
	return lastStage;

}

void addUR(UndoRedoRecord* arr, TUndo* t)
{
	if (arr->length == arr->capacity)
	{
		arr->capacity *= 1.5;
		arr->stages = (TUndo**)realloc(arr->stages, arr->capacity * sizeof(TUndo*));
		arr->stages[arr->length] = createCopy(t);
		arr->length++;
	}
	else {
		arr->stages[arr->length] = createCopy(t);
		arr->length++;
	}

}

//UndoRedoRecord* emptyRecord(UndoRedoRecord* arr)
//{
//	destroyUR(arr);
//	UndoRedoRecord* emptyarr;
//	emptyarr = createRecord(50);
//	return emptyarr;
//}