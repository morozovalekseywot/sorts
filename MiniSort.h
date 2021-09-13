#pragma once

#include "Sorts.h"

// library sort, r включительно
template<typename T>
void STlSort(vector<T> &a, int left, int right)
{
    sort(a.begin() + left, a.begin() + right + 1);
}

template<typename T>
void CountSort(vector<T> &a, int l, int r)
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

    vt counts(max - min + 1, 0);

    for (int elem: a)
        counts[elem - min]++;

    int index = l;
    for (int i = 0; i < counts.size(); i++)
        if (counts[i] != 0)
            for (int j = 0; j < counts[i]; j++)
                a[index++] = i + min;

    assert(index == r + 1);
}

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
