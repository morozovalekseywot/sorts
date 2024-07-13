#pragma once

#include "Sorts.h"

template<typename T>
void InsertBinarySort(vector<T> &a, int l, int r)
{
    // r - включительно
    for (int i = l + 1; i <= r; i++)
    {
        // upper bound находит первый элемент больше данного
        auto it = upper_bound(a.begin() + l, a.begin() + i, a[i]);
        for (int j = i; j > distance(a.begin(), it); j--)
            swap(a[j], a[j - 1]);
    }
}

template<typename T>
void InsertSort(vector<T> &a, int l, int r)
{
    // r - включительно
    for (int i = l + 1; i <= r; i++)
    {
        int j = i;
        while (j > 0 && a[j - 1] > a[j])
        {
            swap(a[j], a[j - 1]);
            j--;
        }
    }
}
