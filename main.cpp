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
            cout << sortName << " Error\n";
            return;
        }
    }
    cout << sortName << "\n--- " << time.count() / 1e3 << " microseconds ---\n";
}

void BenchSortFunc(string sortName, void (*sortFunc)(vector<int> &, int, int), vector<int> &a, int n)
{
    string path = "../graphics/";
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
                cout << sortName << " Error\n";
                file.close();
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
}

int main()
{
    int n;
    //srand(time(NULL));
    //cin >> n;
    n = 100000;
    ArrayGenerator generator(n);
    vi a = generator.GenerateRandomArray();
    Bench(a, n);

//    TestSortFunc("Timsort", TimSort, a, 0, n - 1);
//    TestSortFunc("STLSort", STlSort, a, 0, n - 1);
//    TestSortFunc("MergeSort", MergeSort, a, 0, n - 1);
//    TestSortFunc("FastMergeSort", FastMergeSort, a, 0, n - 1);
//    TestSortFunc("HoarSort", HoarSort, a, 0, n - 1);
//    TestSortFunc("InsertSort", InsertSort, a, 0, n - 1);
//    TestSortFunc("InsertBinarySort", InsertBinarySort, a, 0, n - 1);
//    TestSortFunc("CountSort", CountSort, a, 0, n - 1);

}
