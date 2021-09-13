#pragma once

#include "Sorts.h"

/// слияние двух отсортированных частей массива: [l,med]+[med+1,r]
template<typename T>
void merge(vector<T> &a, int l, int med, int r)
{
    int i = l, j = med + 1, size = 0;
    vector<T> ans(r - l + 1);
    while (i <= med && j <= r)
    {
        if (a[i] < a[j])
            ans[size++] = a[i++];
        else
            ans[size++] = a[j++];
    }

    while (i <= med)
        ans[size++] = a[i++];
    while (j <= r)
        ans[size++] = a[j++];

    if (size != r - l + 1)
    {
        cerr << "Error in function merge\n" << size << " != " << r - l + 1 << "\n";
        if (r - l + 1 < 20)
        {
            cout << "\na = {";
            for (i = l; i <= r; i++)
                cout << a[i] << ", ";
            cout << "}\nans ={";
            for (i = 0; i < size; i++)
                cout << ans[i] << ", ";
            cout << "}\n";
        }
        throw runtime_error("Error in function merge: size != r-l+1");
    }

    size = 0;
    for (i = l; i <= r; i++)
        a[i] = ans[size++];
}

template<typename T>
void MergeSort(vector<T> &a, int l, int r)
{
    if (l >= r)
        return;
    int med = (l + r) / 2;
    MergeSort(a, l, med);
    MergeSort(a, med + 1, r);
    merge(a, l, med, r);
}

template<typename T>
void FastMergeSort(vector<T> &a, int left, int right)
{
    for (int i = left; i < right; i += 2)
    {
        if (a[i] > a[i + 1])
            swap(a[i], a[i + 1]);
    }

    int k, l;
    for (k = 4; k < right - left + 1; k *= 2)
    {
        for (l = left; l + k / 2 <= right; l += k)
            merge(a, l, l + k / 2 - 1, min(l + k - 1, right));
    }

    l = 0;
    while (l < right && a[l] <= a[l + 1])
        l++;
    merge(a, left, l, right);
}
