#pragma once

#include "Sorts.h"

template<typename T>
void HoarSort(vector<T> &a, int first, int last)
{
    int med = a[(first + last) / 2], i = first, j = last;
    while (i <= j)
    {
        while (a[i] < med)
            ++i;
        while (a[j] > med)
            --j;
        if (i <= j)
        {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    if (first < j)
        HoarSort(a, first, j);
    if (i < last)
        HoarSort(a, i, last);
}
