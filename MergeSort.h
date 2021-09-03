#pragma once

#include "Sorts.h"

void MergeSort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;
    int med = (l + r) / 2;
    MergeSort(a, l, med);
    MergeSort(a, med + 1, r);
    int i = l, j = med + 1, index = 0;
    vector<int> b(r - l + 1);
    while (index <= r - l)
    {
        if (i > med)
        {
            while (index <= r - l)
                b[index++] = a[j++];
            break;
        }
        if (j > r)
        {
            while (index <= r - l)
                b[index++] = a[i++];
            break;
        }
        if (a[j] < a[i])
            b[index++] = a[j++];
        else
            b[index++] = a[i++];
    }
    for (i = 0; i <= r - l; ++i)
        a[l + i] = b[i];
    b.clear();
}


void FastMergeSort(vector<int> &a, int left, int right)
{
    int n = right + 1;
    int i, j, k, l;
    for (i = left; i < right; i += 2)
    {
        if (a[i] > a[i + 1])
            swap(a[i], a[i + 1]);
    }

    for (k = 4; k / (right - left + 1) < 2; k *= 2)
    {
        for (l = left; l < n; l += k)
        {
            i = l;
            int index = 0;
            vector<int> b(k);
            int med = l + k / 2, r = min(n, l + k);
            j = med;
            while (index < k)
            {
                if (i >= med)
                {
                    while (index < k && j < r)
                        b[index++] = a[j++];
                    break;
                }
                if (j >= r)
                {
                    while (index < k && i < med)
                        b[index++] = a[i++];
                    break;
                }
                if (a[j] < a[i])
                    b[index++] = a[j++];
                else
                    b[index++] = a[i++];
            }
            for (i = 0; i < index; ++i)
                a[l + i] = b[i];
        }
    }
}
