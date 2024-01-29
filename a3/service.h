#pragma once
#include "domain.h"
#include "repository.h"

/// <summary>
/// Attempts to add an element to a given DynamicArray, given by the characteristics of a medicine.
/// </summary>
/// <param name="arr">Pointer to a DynamicArray.</param>
/// <param name="name">Name of medicine to be added.</param>
/// <param name="concentration">Concentration of medicine to be added.</param>
/// <param name="quantity">Quantity of medicine to be added.</param>
/// <param name="Price">Price of medicine to be added.</param>
/// <returns>1 if the given medicine does not already belong to the DynamicArray, 2 if it does and its quantity had only been updated.</returns>
int addMedicineService(DynamicArray* arr, char name[], double concentration, int quantity, double price);

/// <summary>
/// Deletes the element with the given position from a DynamicArray.
/// </summary>
/// <param name="arr">Pointer to a DynamicArray.</param>
/// <param name="pos">Position of medicine to be deleted.</param>
void deleteMedicineService(DynamicArray* arr, int poz);

/// <summary>
/// Updates the quantity of a medicine with the given position in a DynamicArray.
/// </summary>
/// <param name="arr">Pointer to a DynamicArray.</param>
/// <param name="pos">Position of medicine to be updated.</param>
/// <param name="q">The quantity to be added to the given medicine.</param>
void updateMedicineService(DynamicArray* arr, int poz, int q);

/// <summary>
/// Checks if there are any results to a string search in a given DynamicArray.
/// </summary>
/// <param name="arr">Pointer to a DynamicArray.</param>
/// <param name="str">String to be searched</param>
/// <returns>1 if the given string can be found in any of the names of elements in the DynamicArray, 0 if otherwise.</returns>
int searchString(DynamicArray* arr, char str[]);

/// <summary>
/// Checks if a medicine with the given position in a DynamicArray has a quantity below a given one.
/// </summary>
/// <param name="arr">Pointer to a DynamicArray.</param>
/// <param name="pos">Position of medicine to be checked.</param>
/// <param name="q">The quantity to be compared.</param>
/// <returns>1 if the given medicine is in short supply compared to the given quantity, 0 if otherwise.</returns>
int shortSupplyService(DynamicArray* arr, int poz, int q);
