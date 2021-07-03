#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "heap.h"
#include "QuickSort.h"
using namespace std;
using namespace DS;
int skipEmptyHeaps(Heap** heaps, int length);
void freeHeaps(Heap** heaps, int length);
void kWayMerge(int A[], int k, int left, int right);
bool isNumber(const string& str);
void loadToArray(int n, int* arr, string inputFileName);
void arrayToFile(int n, int* arr, string outputFileName);