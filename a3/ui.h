#pragma once
#include "domain.h"
#include "repository.h"
#include "service.h"


void printMenu();
void initialize(DynamicArray* arr);
void updateMedicineUI(DynamicArray* arr, UndoRedoRecord* undo, UndoRedoRecord* redos);
void deleteMedicineUI(DynamicArray* arr, UndoRedoRecord* undo, UndoRedoRecord* redos);
void addMedicineUI(DynamicArray* arr, UndoRedoRecord* undo, UndoRedoRecord* redos);
void searchByStringUI(DynamicArray* arr);
void shortSupplyUI(DynamicArray* arr);
void undoUI(UndoRedoRecord* undos, UndoRedoRecord* redos, DynamicArray* currentStage);
void redoUI(UndoRedoRecord* undos, UndoRedoRecord* redos, DynamicArray* currentStage);
void exitUI(UndoRedoRecord* undos, UndoRedoRecord* redos, DynamicArray* arr);
void run();
