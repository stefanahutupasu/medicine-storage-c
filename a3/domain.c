#define _CRT_SECURE_NO_WARNINGS
#include "domain.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

Medicine* createMedicine(char* name, double concentration, int quantity, double price)
{
	Medicine* m = (Medicine*)malloc(sizeof(Medicine));
	m->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(m->name, name);
	m->concentration = concentration;
	m->quantity = quantity;
	m->price = price;
	return m;
}

char* getName(Medicine* m)
{
	return m->name;
}

double getConcentration(Medicine* m)
{
	return m->concentration;
}

int getQuantity(Medicine* m)
{
	return m->quantity;
}

double getPrice(Medicine* m)
{
	return m->price;
}


void toString(Medicine* m, char str[])
{
	sprintf(str, "Name: %s; Concentration: %.2lf; Quantity: %d; Price: %.2lf;", m->name, m->concentration, m->quantity, m->price);
}


Medicine* copyMedicine(Medicine* m)
{
	Medicine* newm = (Medicine*)malloc(sizeof(Medicine));
	newm->name = (char*)malloc(sizeof(char) * (strlen(m->name) + 1));
	strcpy(newm->name, m->name);
	newm->concentration = m->concentration;
	newm->price = m->price;
	newm->quantity = m->quantity;
	return newm;
}

void destroyMedicine(Medicine* m)
{
	free(m->name);
	free(m);
}
