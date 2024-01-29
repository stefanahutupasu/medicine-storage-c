#pragma once
#include "domain.h"

typedef Medicine TElement;


typedef struct
{
	TElement** elems;
	int length;
	int capacity;
} DynamicArray;

typedef DynamicArray TUndo;
typedef struct
{
	TUndo** stages;
	int length;
	int capacity;
}UndoRedoRecord;

/// <summary>
/// Creates a dynamic array of generic elements, with a given capacity.
/// </summary>
/// <param name="capacity">Integer, maximum capacity for the dynamic array.</param>
/// <returns>A pointer the the created dynamic array.</returns>
DynamicArray* createDynamicArray(int capacity);

/// <summary>
/// Destroys a dynamic array of generic elements.
/// </summary>
/// <param name="arr">Pointer to a DynamicArray.</param>
void destroy(DynamicArray* arr);

/// <summary>
/// Resizes a dynamic array of generic elements, multiplying the capacity by 1.5.
/// </summary>
/// <param name="arr">Pointer to a DynamicArray.</param>
void resize(DynamicArray* arr);

/// <summary>
/// Adds an element to a DynamicArray.
/// </summary>
/// <param name="arr">Pointer to a DynamicArray.</param>
/// <param name="t">Pointer to a TElement.</param>
void add(DynamicArray* arr, TElement* t);

/// <summary>
/// Finds a medicine with the given name and concentration in a DynamicArray.
/// </summary>
/// <param name="arr">Pointer to a DynamicArray.</param>
/// <param name="name">Given name for the medicine to be found.</param>
/// <param name="concentration">Given concentration for the medicine to be found.</param>
/// <returns>An integer representing the position of that medicine in the DynamicArray, or -1 if it cannot be found.</returns>
int getMedicine(DynamicArray* arr, char name[], double concentration);

/// <summary>
/// Updates the quantity of a medicine in a given DynamicArray.
/// </summary>
/// <param name="arr">Pointer to a DynamicArray.</param>
/// <param name="position">The position of the medicine to be updated.</param>
/// <param name="newQuantity">The new quantity.</param>
void updateMedicine(DynamicArray* arr, int position, int newQuantity);

/// <summary>
/// Deletes a medicine from a DynamicArray.
/// </summary>
/// <param name="arr">Pointer to a DynamicArray.</param>
/// <param name="position">The position of the medicine to be deleted.</param>
void deleteMedicine(DynamicArray* arr, int position);

/// <summary>
/// Checks if a given string is part of the name of a medicine.
/// </summary>
/// <param name="str">The string to be searched for.</param>
/// <param name="m">The medicine.</param>
/// <returns>1 if the string can be found in the name of the medicine, 0 otherwise.</returns>
int stringMatch(Medicine* m, char str[]);

/// <summary>
/// Swaps two medicines in a DynamicArray
/// </summary>
/// <param name="arr">Pointer to a DynamicArray.</param>
/// <param name="i">Position of the first medicine to be swapped.</param>
/// <param name="j">Position of the second element to be swapped.</param>
void swapElem(DynamicArray* arr, int i, int j);

/// <summary>
/// Sorts a DynamicArray ascending by the name of the medicines.
/// </summary>
/// <param name="arr">Pointer to a DynamicArray.</param>
void sortAscendingByName(DynamicArray* arr);

/// <summary>
/// Creates a record of program stages, with a given capacity.
/// </summary>
/// <param name="capacity">Integer, maximum capacity for the record.</param>
/// <returns>A pointer the the created record.</returns>
UndoRedoRecord* createRecord(int capacity);

/// <summary>
/// Destroys a record of program stages.
/// </summary>
/// <param name="arr">Pointer to a UndoRedoRecord.</param>
void destroyUR(UndoRedoRecord* arr);

/// <summary>
/// Resizes a record of program stages, multiplying the capacity by 1.5.
/// </summary>
/// <param name="arr">Pointer to a UndoRedoRecord.</param>
void resizeUR(UndoRedoRecord* arr);

/// <summary>
/// Creates a copy of a program stage.
/// </summary>
/// <param name="stage">Pointer to a DynamicArray representing the given program stage.</param>
/// <returns>A pointer the the created copy.</returns>
TUndo* createCopy(TUndo* stage);

/// <summary>
/// Adds an element to a UndoRedoRecord.
/// </summary>
/// <param name="arr">Pointer to a UndoRedoRecord.</param>
/// <param name="t">Pointer to a TUndo stage.</param>
void addUR(UndoRedoRecord* arr, TUndo* t);
