#pragma once

#include "Sorts.h"

template<typename T>
struct MergeStruct
{
    vt vec;
    int size;

    explicit MergeStruct(const vt &vec) : vec(vec), size(vec.size())
    {}

    MergeStruct(const vt &a, int left, int right)
    {
        vec = vector<T>(a.begin() + left, a.begin() + right + 1);
        size = right - left + 1;
    }
};

template<typename T>
class MergeMachine
{
private:
    vector<MergeStruct<T>> queue;
    int size = 0;
public:
    void AppendInQueue(const MergeStruct<T> &elem)
    {
        if (queue.size() <= size)
        {
            queue.emplace_back(elem);
            size++;
        } else
            queue[size++] = elem;
        CheckQueue();
    }

    void CheckQueue()
    {
        if (size < 3)
            return;
        // (X > Y + Z) , (Y > Z)
        // Если одно из правил нарушается — массив Y сливается с меньшим из массивов X и Z
        // Повторяется до выполнения обоих правил или полного упорядочивания данных
        // чем меньше индекс тем больше размер
        while (size > 2)
        {
            MergeStruct x = queue[size - 3], y = queue[size - 2], z = queue[size - 1];
            // должно быть x.size>y.size>z.size
            //cout << x.size << " " << y.size << " " << z.size << "\n";
            if (x.size > y.size + z.size && y.size > z.size)
                break;
            if (x.size <= y.size + z.size)
            {
                size--;
                //cout << "Merge x and y " << x.size << " " << y.size << "\n";
                queue[size - 2] = MergeStruct(mergeV1(x, y));
                queue[size - 1] = z;
            } else
            {
                size--;
                //cout << "Merge y and z " << y.size << " " << z.size << "\n";
                queue[size - 1] = MergeStruct(mergeV1(z, y));
            }
        }
    }

    static vector<T> mergeV1(const MergeStruct<T> &a, const MergeStruct<T> &b)
    {
        //cout << a.size << " " << b.size << "\n";
        vector<T> ans(a.size + b.size);
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
            cerr << "Error in function mergeV1\n" << size << " != " << a.size << " + " << b.size << "\n";
            throw runtime_error("Error in function mergeV1: size != a.size + b.size");
        }

        return ans;
    }

    static vector<T> mergeV2(const MergeStruct<T> &a, const MergeStruct<T> &b)
    {
        vector<T> ans(a.size + b.size);
        int i = 0, j = 0, size = 0;

        while (i < a.size && j < b.size)
        {
            if (a.vec[i] < b.vec[j])
                ans[size++] = a.vec[i++];
            else
                ans[size++] = b.vec[j++];
        }

        while (i < a.size)
            ans[size++] = a.vec[i++];
        while (j < b.size)
            ans[size++] = b.vec[j++];

        if (size != a.size + b.size)
        {
            cerr << "Error in function mergeV2\n" << size << " != " << a.size << " + " << b.size << "\n";
            throw runtime_error("Error in function mergeV2: size != a.size + b.size");
        }

        return ans;
    }

    /// merge last and return sorted vector
    vector<T> MergeLast()
    {
        if (size > 2)
        {
            while (size >= 3)
            {
                queue[size - 2] = MergeStruct(mergeV1(queue[size - 1], queue[size - 2]));
                size--;
            }
        }

        if (size == 1)
            return queue[0].vec;

        return mergeV1(queue[size - 1], queue[size - 2]);
    }
};