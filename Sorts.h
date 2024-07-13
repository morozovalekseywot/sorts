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

#define vi vector<int>

/// Сортировка подсчётом
void CountSort(vector<int> &a, int l, int r);

/// Сортировка слиянием с рекурсией
template<typename T>
void MergeSort(vector<T> &a, int l, int r);

/// Сортировка слиянем без рекурсии
template<typename T>
void FastMergeSort(vector<T> &a, int left, int right);

template<typename T>
void TimSort(vector <T> &a, int l, int r);

/// Сортировка вставками
template<typename T>
void InsertSort(vector <T> &a, int l, int r);

/// Сортировка двоичными вставками
template<typename T>
void InsertBinarySort(vector<T> &a, int l, int r);

/// Сортировка Хоара
template<typename T>
void HoarSort(vector<T> &a, int first, int last);

/// Тест сортировок
template<typename T>
void TestSortFunc(string sortName, void sortFunc(vector <T> &a, int l, int r), vector <T> &a, int l, int r);

/// Библиотечная сортировка, r включительно
template<typename T>
void STlSort(vector<T> &a, int left, int right)
{
    sort(a.begin() + left, a.begin() + right + 1);
}
