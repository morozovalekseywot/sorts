#pragma once

#include "Sorts.h"

struct MergeStruct
{
    vi vec;
    int left; // левая граница в исходном массиве
    int right; // правая граница в исходном массиве, включительно
    int size; // размер

    explicit MergeStruct(const vi &vec) : vec(vec), left(-1), right(-1), size(vec.size())
    {}

    MergeStruct(const vi &a, int left, int right) : left(left), right(right)
    {
        size = right - left + 1;
        vec.resize(size);
        for (int i = left; i <= right; i++)
            vec[i - left] = a[i];
    }
};

struct MergeMachine
{
    vector<MergeStruct> queue;
    int size = 0;

    void AppendInQueue(const MergeStruct &elem)
    {
        queue.emplace_back(elem);
        size++;
        CheckQueue();
    }

    void CheckQueue()
    {
        if (size < 3)
            return;
        // (X > Y + Z) ^ (Y > Z)
        // Если одно из правил нарушается — массив Y сливается с меньшим из массивов X и Z
        // Повторяется до выполнения обоих правил или полного упорядочивания данных
        while (size >= 3)
        {
            MergeStruct x = queue[size - 1], y = queue[size - 2], z = queue[size - 3];
            if (x.size <= y.size + z.size || y.size <= z.size)
            {
                if (x.size < z.size)
                {
                    size--;
                    queue.pop_back();
                    queue[size - 1] = MergeStruct(Merge(x, y));
                } else
                {
                    size--;
                    queue.pop_back();
                    queue[size - 1] = x;
                    queue[size - 2] = MergeStruct(Merge(z, y));
                }
            } else
                break;
        }
    }

    static vi Merge(const MergeStruct &a, const MergeStruct &b)
    {
        vi ans(a.size + b.size);
        int i = 0, j = 0, size = 0;

        while (i < a.size && j < b.size)
        {
            if (a.vec[i] == b.vec[j])
            {
                ans[size++] = a.vec[i];
                ans[size++] = b.vec[j];
                i++;
                j++;
                continue;
            }

            while (i < a.size && a.vec[i] < b.vec[j])
            {
                ans[size++] = a.vec[i++];
                // галоп сюда
            }
            if (i == a.size)
                break;

            while (j < b.size && b.vec[j] < a.vec[i])
            {
                ans[size++] = b.vec[j++];
                // галоп сюда
            }
        }

        while (i < a.size)
            ans[size++] = a.vec[i++];
        while (j < b.size)
            ans[size++] = b.vec[j++];

        if (size != a.size + b.size)
        {
            cerr << "Error in function Merge\n" << size << " != " << a.size << " + " << b.size << "\n";
            throw runtime_error("Error in function Merge: size != a.size + b.size");
        }

        return ans;
    }

    /// merge last and return sorted vector
    vi MergeLast()
    {
        if (size > 2 || size <= 0)
        {
            cerr << "\nPrivate size of queue: " << queue.size() << "\nPublic size of queue: " << size << "\n";
            throw runtime_error("Size of MergeMachine.queue >= 2");
        }
        if (size == 1)
            return queue[0].vec;
        return Merge(queue[size - 1], queue[size - 2]);
    }
};