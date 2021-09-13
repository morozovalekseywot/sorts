#pragma once

#include "Sorts.h"
#include <random>

struct ArrayGenerator
{
    int n;

    explicit ArrayGenerator(int n) : n(n)
    {};

    [[nodiscard]] vi GenerateRandomArray() const
    {
        random_device rd;
        mt19937 mersenne(rd());

        vi a(n);
        for (int i = 0; i < n; ++i)
        {
            a[i] = int(mersenne());
            if (a[i] % 2 == 0)
                a[i] = -a[i];
        }

        return a;
    }

    [[nodiscard]] vi GenerateSortedArray() const
    {
        random_device rd;
        mt19937 mersenne(rd());

        vi a(n);
        for (int i = 0; i < n; ++i)
        {
            a[i] = int(mersenne());
            if (a[i] % 2 == 0)
                a[i] = -a[i];
        }

        sort(a.begin(), a.end());
        return a;
    }

    [[nodiscard]] vi GenerateReverseArray() const
    {
        vi a = GenerateSortedArray();
        reverse(a.begin(), a.end());
        return a;
    }

    [[nodiscard]] vi GenerateRealArray() const
    {
        vi a = GenerateRandomArray();
        for (int i = 0; i < n; i++)
        {
            int k = min(i + (rand() % n) / 10, n);
            sort(a.begin() + i, a.begin() + k);
            if (k % 2 == 0)
                reverse(a.begin() + i, a.begin() + k);
            i += k - 1 + rand() % k;
        }

        return a;
    }

    [[nodiscard]] vi GenerateSwapArray() const
    {
        random_device rd;
        mt19937 mersenne(rd());

        vi a = GenerateSortedArray();
        int count_of_swap = n / 20 + mersenne() % (n / 20);

        for (int i = 0; i < count_of_swap; i++)
        {
            swap(a[mersenne() % (n / 2)], a[n / 2 + mersenne() % (n / 2)]);
        }

        return a;
    }
};