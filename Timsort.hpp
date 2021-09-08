#pragma once

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
#include "MergeMachine.hpp"

using namespace std;
#define vi vector <int>

int getMinrun(int n)
{
    int r = 0;           // станет 1 если среди сдвинутых битов будет хотя бы 1 ненулевой
    while (n >= 64)
    {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

void subSort(vector<int> &a, int l, int r)
{
    InsertBinarySort(a, l, r);
}

void TimSort(vector<int> &a, int l, int r)
{
    // r - включительно
    // int n = r - l + 1
    int iter = l;
    int minrun = getMinrun(r - l + 1);
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
                subSort(a, iter, iter + minrun - 1);
                machine.AppendInQueue(MergeStruct(a, iter, iter + minrun - 1));
                iter += minrun;
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
                subSort(a, iter, iter + minrun);
                machine.AppendInQueue(MergeStruct(a, iter, iter + minrun - 1));
                iter += minrun;
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
        subSort(a, iter, r);
        machine.AppendInQueue(MergeStruct(a, iter, r));
    }

    a = machine.MergeLast();
}
