#pragma once

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

#define vi vector <int>

/// Сортировка слиянием с рекурсией
void MergeSort(vector<int> &a, int l, int r);

/// Сортировка слиянем без рекурсии
void FastMergeSort(vector<int> &a, int left, int right);

void TimSort(vi &a, int l, int r);

/// Сортировка вставками
void InsertSort(vi &a, int l, int r);

/// Тест сортировок
void TestSortFunc(string sortName, void sortFunc(vi &a, int l, int r), vi &a, int l, int r);
