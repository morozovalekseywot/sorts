#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>

#pragma once
using namespace std;

void fast_merge_sort(vector<int> &a, int left, int right)
{
    int n = right + 1;
    int i, j, k, l;
    for (i = left; i < n - 1; i += 2)
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

void merge_sort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;
    int med = (l + r) / 2;
    merge_sort(a, l, med);
    merge_sort(a, med + 1, r);
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

void hoar_sort(vector<int> &a, int first, int last)
{
    int med = a[(first + last) / 2], i = first, j = last, centr = (first + last) / 2;
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
    if (centr - first > 1)
        hoar_sort(a, first, j);
    if (last - centr > 1)
        hoar_sort(a, i, last);
}