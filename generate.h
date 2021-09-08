#pragma once

#include "Sorts.h"

struct ArrayGenerator
{
    int n;

    explicit ArrayGenerator(int n) : n(n)
    {};

    [[nodiscard]] vi GenerateRandomArray() const
    {
        vi a(n);
        for (int i = 0; i < n; ++i)
            a[i] = rand() % INT32_MAX;

        return a;
    }

    [[nodiscard]] vi GenerateSortedArray() const
    {
        vi a(n);
        for (int i = 0; i < n; ++i)
            a[i] = rand() % INT32_MAX;

        sort(a.begin(), a.end());
        return a;
    }

    [[nodiscard]] vi GenerateReverseArray() const
    {
        vi a(n);
        a[0] = INT32_MAX / 10;
        for (int i = 1; i < n; ++i)
            a[i] = a[i - 1] - rand() % INT16_MAX;

        return a;
    }

    [[nodiscard]] vi GenerateRealArray() const
    {
        vi a = GenerateRandomArray();
        for (int i = 0; i < n; i++)
        {
            int k = min(i + (rand() % n) / 10, n);
            sort(a.begin() + i, a.begin() + k);
            int count_of_swap = rand() % (k / 4);
            for (int j = 0; j < count_of_swap; j++)
            {
                swap(a[i + rand() % (k - i)], a[i + rand() % (k - i)]);
            }
            i += k - 1;
        }

        return a;
    }
};