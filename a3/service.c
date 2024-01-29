#include <stdio.h>
#include <stdlib.h>
#include "repository.h"



int addMedicineService(DynamicArray* arr, char name[], double concentration, int quantity, double price)
{
	int i = getMedicine(arr, name, concentration);
	if (i == -1) //medicine does not exist -> must add
	{
		Medicine* m = createMedicine(name, concentration, quantity, price);
		add(arr, m);
		return 1;
	}
	else //medicine already in stock -> will only update quantity
		updateMedicine(arr, i, quantity + arr->elems[i]->quantity);
	return 2;
}

void deleteMedicineService(DynamicArray* arr, int poz)
{
	deleteMedicine(arr, poz);
}

void updateMedicineService(DynamicArray* arr,int poz, int q)
{
	arr->elems[poz]->quantity += q;
}

int searchString(DynamicArray* arr, char str[])
{
	sortAscendingByName(arr);
	for (int i = 0; i < arr->length; i++)
		if (stringMatch(arr->elems[i], str))
			return 1;
	return 0;
}

int shortSupplyService(DynamicArray* arr, int poz, int q)
{
	if (arr->elems[poz]->quantity < q) return 1;
	return 0;
}