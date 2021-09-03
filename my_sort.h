#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>

#pragma once
using namespace std;

// library sort, r включительно
void STlSort(vector<int> &a, int left, int right)
{
    sort(a.begin() + left, a.begin() + right + 1);
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