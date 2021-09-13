#pragma once

#include "Sorts.h"

template<class data>
concept arr =
requires(data &seq){
    seq.getLength() != 0;
    swappable<data>;
    equality_comparable<data[0]>;
};

template<typename T, class data>
requires arr<data>
class ISorter
{
public:
    void CountSortSequence(data &seq, int left, int right)
    {
        if (right < left || left < 0 || right >= seq.getLength())
            throw out_of_range("right < left in function CountSortSequence");
        vector<T> a(right - left + 1);
        for (int i = left; i <= right; i++)
            a[i - left] = seq[i];

        CountSort(a, 0, right - left + 1);

        for (int i = left; i <= right; i++)
            seq[i] = a[i - left];
    }

    void MergeSortSequence(data &seq, int left, int right)
    {
        if (right < left || left < 0 || right >= seq.getLength())
            throw out_of_range("right < left in function MergeSortSequence");
        vector<T> a(right - left + 1);
        for (int i = left; i <= right; i++)
            a[i - left] = seq[i];

        MergeSort(a, 0, right - left + 1);

        for (int i = left; i <= right; i++)
            seq[i] = a[i - left];
    }

    void FastMergeSortSequence(data &seq, int left, int right)
    {
        if (right < left || left < 0 || right >= seq.getLength())
            throw out_of_range("right < left in function FastMergeSortSequence");
        vector<T> a(right - left + 1);
        for (int i = left; i <= right; i++)
            a[i - left] = seq[i];

        FastMergeSort(a, 0, right - left + 1);

        for (int i = left; i <= right; i++)
            seq[i] = a[i - left];
    }

    void TimSortSequence(data &seq, int left, int right)
    {
        if (right < left || left < 0 || right >= seq.getLength())
            throw out_of_range("right < left in function TimSortSequence");
        vector<T> a(right - left + 1);
        for (int i = left; i <= right; i++)
            a[i - left] = seq[i];

        TimSort(a, 0, right - left + 1);

        for (int i = left; i <= right; i++)
            seq[i] = a[i - left];
    }

    void InsertSortSequence(data &seq, int left, int right)
    {
        if (right < left || left < 0 || right >= seq.getLength())
            throw out_of_range("right < left in function InsertSortSequence");
        vector<T> a(right - left + 1);
        for (int i = left; i <= right; i++)
            a[i - left] = seq[i];

        InsertSort(a, 0, right - left + 1);

        for (int i = left; i <= right; i++)
            seq[i] = a[i - left];
    }

    void InsertBinarySortSequence(data &seq, int left, int right)
    {
        if (right < left || left < 0 || right >= seq.getLength())
            throw out_of_range("right < left in function InsertBinarySort");
        vector<T> a(right - left + 1);
        for (int i = left; i <= right; i++)
            a[i - left] = seq[i];

        InsertBinarySort(a, 0, right - left + 1);

        for (int i = left; i <= right; i++)
            seq[i] = a[i - left];
    }

    void HoarSortSequence(data &seq, int left, int right)
    {
        if (right < left || left < 0 || right >= seq.getLength())
            throw out_of_range("right < left in function HoarSortSequence");
        vector<T> a(right - left + 1);
        for (int i = left; i <= right; i++)
            a[i - left] = seq[i];

        HoarSort(a, 0, right - left + 1);

        for (int i = left; i <= right; i++)
            seq[i] = a[i - left];
    }
};