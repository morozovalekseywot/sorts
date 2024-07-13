#pragma once

#include "Sorts.h"

void CountSort(vector<int> &a, int l, int r)
{
    // нахождение интервала чисел
    int max = a[l], min = a[l];
    for (int i = l; i <= r; i++)
    {
        if (a[i] > max)
            max = a[i];
        else if (a[i] < min)
            min = a[i];
    }

    vi counts(max - min + 1, 0);

    for (int elem: a)
        counts[elem - min]++;

    int index = l;
    for (int i = 0; i < counts.size(); i++)
        if (counts[i] != 0)
            for (int j = 0; j < counts[i]; j++)
                a[index++] = i + min;

    assert(index == r + 1);
}