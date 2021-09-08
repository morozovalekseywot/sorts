#include "MiniSort.h"
#include "Timsort.hpp"
#include "MergeSort.h"
#include "generate.h"
#include <fstream>
#include <cstdlib>
#include <iomanip>

#define all(v) v.begin(), v.end()
#define vpii vector<pair<int, int>>
#define CIN                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl "\n"

void TestSortFunc(string sortName, void (*sortFunc)(vector<int> &, int, int), vector<int> &a, int l, int r)
{
    vi b = a;
    auto begin = steady_clock::now();
    sortFunc(b, l, r);
    auto end = steady_clock::now();
    auto time = duration_cast<microseconds>(end - begin);
    for (int i = l; i < r; i++)
    {
        if (b[i] > b[i + 1])
        {
            string path = "../";
            path.append("Error.txt");
            ofstream err(path, ios_base::trunc);
            err << sortName << "\n";
            err << "i = " << i << ", b[i]=" << b[i] << ", b[i+1] = " << b[i + 1] << "\n";
            cout << "size = " << i << "\n";
            for (i = 0; i <= r; i++)
                err << b[i] << " ";
            err.close();
            cout << sortName << " Error\n";
            return;
        }
    }
    cout << sortName << "\n--- " << time.count() / 1e3 << " microseconds ---\n";
}

void BenchSortFunc(string sortName, void (*sortFunc)(vector<int> &, int, int), vector<int> &a, int n)
{
    string path = "../graphics/real/";
    path.append(sortName.begin(), sortName.end());
    path.append(".txt");
    ofstream file(path, ios_base::trunc);

    for (int i = n / 100; i <= n; i += n / 100)
    {
        vi b(a.begin(), a.begin() + i);

        auto begin = steady_clock::now();
        sortFunc(b, 0, i - 1);
        auto end = steady_clock::now();
        auto time = duration_cast<microseconds>(end - begin);

        for (int j = 0; j < i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                file.close();
                path = "../";
                path.append("Error.txt");
                ofstream err(path, ios_base::trunc);
                err << sortName << "\n";
                err << "j = " << j << ", b[j]=" << b[j] << ", b[j+1] = " << b[j + 1] << "\n";
                err << "size = " << i << "\n";
                for (j = 0; j < i; j++)
                    err << b[j] << "\n";
                err.close();
                cout << sortName << " Error\n";
                return;
            }
        }

        file << i << " " << time.count() / 1e3 << "\n";
    }
    file.close();
}

void Bench(vi &a, int n)
{
    BenchSortFunc("HoarSort", HoarSort, a, n);
    BenchSortFunc("MergeSort", MergeSort, a, n);
    BenchSortFunc("FastMergeSort", FastMergeSort, a, n);
    BenchSortFunc("STLSort", STlSort, a, n);
    BenchSortFunc("Timsort", TimSort, a, n);
//    BenchSortFunc("CountSort", CountSort, a, n);
}

void Bench2(vi &a, int n)
{
    BenchSortFunc("InsertBinarySort", InsertBinarySort, a, n);
    BenchSortFunc("InsertSort", InsertSort, a, n);
}

int main()
{
    int n;
    srand(time(NULL));
    //cin >> n;
    n = 100000;
    ArrayGenerator generator(n);
    vi randomArray = generator.GenerateRandomArray();
    vi sortArray = generator.GenerateSortedArray();
    vi reverseArray = generator.GenerateReverseArray();
    vi realArray = generator.GenerateRealArray();

    Bench(realArray, n);
    Bench2(realArray, n / 50);

//    TestSortFunc("Timsort", TimSort, realArray, 0, n - 1);
//    TestSortFunc("STLSort", STlSort, randomArray, 0, n - 1);
//    TestSortFunc("MergeSort", MergeSort, randomArray, 0, n - 1);
//    TestSortFunc("FastMergeSort", FastMergeSort, randomArray, 0, n - 1);
//    TestSortFunc("HoarSort", HoarSort, randomArray, 0, n - 1);
//    TestSortFunc("InsertSort", InsertSort, randomArray, 0, n - 1);
//    TestSortFunc("InsertBinarySort", InsertBinarySort, randomArray, 0, n - 1);
//    TestSortFunc("CountSort", CountSort, randomArray, 0, n - 1);

}
