#pragma once

#include "Sorts.h"

// library sort, r включительно
void STlSort(vector<int> &a, int left, int right)
{
    sort(a.begin() + left, a.begin() + right + 1);
}

void CountSort(vector<int> &vec, int l, int r)
{
    // нахождение интервала чисел
    int max = vec[l], min = vec[l];
    for (int i = l; i <= r; i++)
    {
        if (vec[i] > max)
            max = vec[i];
        else if (vec[i] < min)
            min = vec[i];
    }

    vector<int> counts(max - min + 1, 0);

    for (int i: vec)
        counts[i - min]++;

    int index = l;
    for (int i = 0; i < counts.size(); i++)
    {
        if (counts[i] != 0)
        {
            for (int j = 0; j < counts[i]; j++)
                vec[index++] = i + min;
        }
    }

    assert(index == r + 1);
}

void InsertSort(vector<int> &a, int l, int r)
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

// не работает пока что
void HoarSort(vector<int> &a, int first, int last)
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