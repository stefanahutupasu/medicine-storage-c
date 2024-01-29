#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"



void printMenu()
{
	printf("Available commands:\n");
	printf("1. Add medicine;\n");
	printf("2. Delete medicine;\n");
	printf("3. Update medicine;\n");
	printf("4. Search by string (sorting = ascending by name);\n");
	printf("5. View medicine in short supply.\n");
	printf("6. Undo.\n");
	printf("7. Redo.\n");
	printf("0. Exit.\n");
}

void initialize(DynamicArray* arr)
{
	add(arr, createMedicine("Aspirin", 0.5, 10, 20.5));
	add(arr, createMedicine("Vitamin C", 20.5, 15, 10.5));
	add(arr, createMedicine("Vicodin", 1.5, 20, 23.5));
	add(arr, createMedicine("Vitamin D", 30, 40, 20));
	add(arr, createMedicine("Claritine", 0.5, 50, 35.5));
}

void updateMedicineUI(DynamicArray* arr, UndoRedoRecord* undos, UndoRedoRecord* redos)
{
	char name[100];
	double concentration;
	char str[100];
	printf("Enter medicine name: ");
	fgets(name, 100, stdin);
	name[strlen(name) - 1] = NULL;
	printf("Enter medicine concentration: ");
	fgets(str, 100, stdin);
	concentration = atof(str);
	int addQuantity;
	int ok = 0;
	while (!ok) {
		printf("Enter the quantity you wish to add: ");
		fgets(str, 100, stdin);
		addQuantity = atoi(str);
		if (addQuantity != 0) ok = 1; else printf("Invalid input: the quantity you wish to add/substract is either 0 or of invalid format!\n");
	}
	if (getMedicine(arr, name, concentration) != -1)
	{
		
		for (int i = 0; i < redos->length; i++)destroy(redos->stages[i]);
		redos->length = 0;
		addUR(undos, arr);
		updateMedicineService(arr, getMedicine(arr, name, concentration), addQuantity);
		printf("Medicine updated successfully!\n");
	}
	else printf("Medicine specified does not exist!\n");
}

void deleteMedicineUI(DynamicArray* arr, UndoRedoRecord* undos, UndoRedoRecord* redos)
{
	char name[100];
	double concentration;
	char str[100];
	printf("Enter medicine name: ");
	fgets(name, 100, stdin);
	name[strlen(name) - 1] = NULL;
	int ok = 0;
	while(!ok){
		printf("Enter medicine concentration: ");
		fgets(str, 100, stdin);
		concentration = atof(str);
		if (concentration > 0)ok = 1; else printf("Invalid input: concentration is either 0, negative, or of invalie format!\n");
	}
	
	if (getMedicine(arr, name, concentration) != -1)
	{
		for (int i = 0; i < redos->length; i++)destroy(redos->stages[i]);
		redos->length = 0;
		addUR(undos, arr);
		deleteMedicineService(arr, getMedicine(arr, name, concentration));
		printf("Medicine deleted successfully!\n");
	}
	else printf("Medicine specified does not exist!\n");

}

void addMedicineUI(DynamicArray* arr, UndoRedoRecord* undos, UndoRedoRecord* redos)
{
	char name[100];
	double concentration;
	int quantity;
	double price;
	char str[100];
	printf("Enter medicine name: ");
	fgets(name, 100, stdin);
	name[strlen(name) - 1] = NULL;
	int ok = 0;
	while(!ok){
		printf("Enter medicine concentration: ");
		fgets(str, 100, stdin);
		concentration = atof(str);
		if (concentration > 0)ok = 1; else printf("Invalid input: concentration is either 0, negative, or of invalie format!\n");
	}
	ok = 0;
	while(!ok)
	{ printf("Enter medicine quantity: ");
	fgets(str, 100, stdin);
	quantity = atoi(str);
	if (quantity > 0) ok = 1; else printf("Invalid input: you cannot add a medicine with a non-positive quantity to the stock! Make sure you entered a positive integer!\n");
	}
	
	ok = 0;
	while(!ok)
	{
		printf("Enter medicine price: ");
		fgets(str, 100, stdin);
		price = atof(str);
		if (price > 0)ok = 1; else printf("Invalid input: the price should be positive. You cannot sell medicine for free. Make sure you entered a positive rational number!\n");
	}
	
	
	for (int i=0; i < redos->length; i++)destroy(redos->stages[i]);
	redos->length = 0;
	addUR(undos, arr);

	if (addMedicineService(arr, name, concentration, quantity, price) == 1)
	{
		
		printf("Medicine added successfully to the stock!\n");
	}
	else { printf("Medicine with given name and concentration already exists: quantity has been updated.\n"); }

}

void searchByStringUI(DynamicArray* arr)
{
	char str[100], strprint[100];
	printf("Enter a string:");
	fgets(str, 100, stdin);
	str[strlen(str) - 1] = NULL;

	if (searchString(arr, str))
	{
		for (int i = 0; i < arr->length; i++)
			if (stringMatch(arr->elems[i], str))
			{
				char strprint[100];
				toString(arr->elems[i], strprint);
				printf("%s\n", strprint);
			}
	}
	else printf("No medicine found.\n");
}

void shortSupplyUI(DynamicArray* arr)
{
	char str[100];
	printf("Enter quantity: ");
	fgets(str, 100, stdin);
	int q = atoi(str);
	int found = 0;
	for(int i=0;i<arr->length;i++)
		if (shortSupplyService(arr, i, q))
		{
			char strprint[100];
			toString(arr->elems[i], strprint);
			printf("%s\n", strprint);
			found = 1;
		}
	if (!found) printf("There is no medicine which has a lower quantity than the specified one.\n");
}



void exitUI(UndoRedoRecord* undos, UndoRedoRecord* redos, DynamicArray* arr)
{
	printf("Bye-bye!\n");
	destroy(arr);
	destroyUR(undos);
	destroyUR(redos);
}


void run()
{
	printf("Welcome to the 'Smiles' Pharmacy!\n");
	printMenu();
	DynamicArray* repo = createDynamicArray(50);
	UndoRedoRecord* undos = createRecord(50);
	UndoRedoRecord* redos = createRecord(50);

	initialize(repo);
	int ok = 1;
	while (ok)
	{
		printf("Enter a command:");
		char command[10];
		fgets(command, 10, stdin);
		int commandi = atoi(command);
		switch (commandi)
		{
		case 1:
			addMedicineUI(repo, undos, redos);
			break;
		case 2:
			deleteMedicineUI(repo, undos, redos);
			break;
		case 3:
			updateMedicineUI(repo, undos, redos);
			break;
		case 4:
			searchByStringUI(repo);
			break;
		case 5:
			shortSupplyUI(repo);
			break;
		case 6:
			if (undos->length > 0)
			{
				addUR(redos, repo);
				destroy(repo);
				repo = createCopy(undos->stages[undos->length - 1]);
				destroy(undos->stages[undos->length - 1]);
				undos->length -= 1;
				printf("Action un-done.\n");
			}
			else printf("No action left to undo.\n");
			break;
		case 7:
			if (redos->length > 0)
			{
				addUR(undos, repo);
				destroy(repo);
				repo = createCopy(redos->stages[redos->length - 1]);
				destroy(redos->stages[redos->length - 1]);
				redos->length -= 1;
				printf("Action re-done.\n");
			}
			else printf("No action left to redo.\n");
			break;
		case 0:
			exitUI(undos, redos, repo);
			ok = 0;
			break;
		}
		

	}
}