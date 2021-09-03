#pragma once

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
#include "MergeMachine.hpp"

using namespace std;
#define vi vector <int>

int GetMinrun(int n)
{
    int r = 0;           // станет 1 если среди сдвинутых битов будет хотя бы 1 ненулевой
    while (n >= 64)
    {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

// Сортировка вставками
void InsertSort(vi &a, int l, int r)
{
    // r - включительно
    for (int i = l + 1; i < r; i++)
    {
        // upper bound находит первый элемент больше данного
        auto it = upper_bound(a.begin() + l, a.begin() + i, a[i]);
        for (int j = i; j > distance(a.begin(), it); j--)
            swap(a[j], a[j - 1]);
    }
}


void TimSort(vi &a, int l, int r)
{
    // r - включительно
    // int n = r - l + 1
    int iter = l;
    int minrun = GetMinrun(r - l + 1);
    MergeMachine machine;

    // разбиение и сортировка
    while (iter < r - minrun)
    {
        int i = iter;
        if (a[i] <= a[i + 1]) // Возрастание
        {
            while (i < r && a[i] <= a[i + 1])
                i++;
            if (i - iter + 1 < minrun)
            {
                InsertSort(a, iter, iter + minrun);
                machine.AppendInQueue(MergeStruct(a, iter, iter + minrun));
                iter += minrun + 1;
            } else
            {
                // уже отсортирован, не надо ничего делать
                machine.AppendInQueue(MergeStruct(a, iter, i));
                iter = i + 1;
            }
        } else // Строгое убывание
        {
            while (i < r && a[i] > a[i + 1])
                i++;
            reverse(a.begin() + iter, a.begin() + i);
            if (i - iter + 1 < minrun)
            {
                InsertSort(a, iter, iter + minrun);
                machine.AppendInQueue(MergeStruct(a, iter, iter + minrun));
                iter += minrun + 1;
            } else
            {
                // уже отсортирован, не надо ничего делать
                machine.AppendInQueue(MergeStruct(a, iter, i));
                iter = i + 1;
            }
        }
    }

    int i = iter;
    if (iter < r)
    {
        while (i < r && a[i] > a[i + 1])
            i++;
        reverse(a.begin() + iter, a.begin() + i);
        InsertSort(a, iter, r);
        machine.AppendInQueue(MergeStruct(a, iter, r));
    }

    vi b = machine.MergeLast();
    a = b;
}
