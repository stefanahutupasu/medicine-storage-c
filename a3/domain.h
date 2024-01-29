#pragma once

typedef struct
{
	char *name;
	double concentration;
	int quantity;
	double price;
} Medicine;

/*
Creates a medicine and returns the poiner to it;
Params:
char* name: the name of the medicine
double concentration: the concentration of the medicine
int quantity: the quantity for the given medicine
double price: the price of that medicine
Returns:
a pointer to the medicine struct
*/
Medicine* createMedicine(char* name, double concentration, int quantity, double price);

/*
Getter for the name of a medicine;
Params:
Medicine* m: the given medicine(more exactly, a pointer to it)
Returns:
char* <name of the medicine>
*/
char* getName(Medicine* m);

/*
Getter for the concentration of a medicine;
Params:
Medicine* m: the given medicine(more exactly, a pointer to it)
Returns:
double <concentration value of the medicine>
*/
double getConcentration(Medicine* m);

/*
Getter for the quantity of a medicine;
Params:
Medicine* m: the given medicine(more exactly, a pointer to it)
Returns:
int <quantity of the medicine>
*/
int getQuantity(Medicine* m);

/*
Getter for the price of a medicine;
Params:
Medicine* m: the given medicine(more exactly, a pointer to it)
Returns:
double <price of the medicine>
*/
double getPrice(Medicine* m);

/*
Appends the information for a medicine to a string;
Params:
Medicine* m: the given medicine(more exactly, a pointer to it)
char str[]: the string to which to append the new text
*/
void toString(Medicine* m, char str[]);

/*
Creates a copy for a medicine;
Params:
Medicine* m: the given medicine(more exactly, a pointer to it)
Returns:
Medicine* <pointer to the copy of the given medicine>
*/
Medicine* copyMedicine(Medicine* m);

/*
Destroys a medicine, freeing up the allocated space for it;
Params:
Medicine* m: the given medicine(more exactly, a pointer to it)
*/
void destroyMedicine(Medicine* m);