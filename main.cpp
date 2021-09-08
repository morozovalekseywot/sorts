#include "MiniSort.h"
#include "Timsort.hpp"
#include "MergeSort.h"
#include "generate.h"

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

int main()
{
    int n;
    //srand(time(NULL));
    cin >> n;
    ArrayGenerator generator(n);
    vi a = generator.GenerateRandomArray();

    TestSortFunc("Timsort", TimSort, a, 0, n - 1);
//    TestSortFunc("STLSort", STlSort, a, 0, n - 1);
//    TestSortFunc("MergeSort", MergeSort, a, 0, n - 1);
//    TestSortFunc("FastMergeSort", FastMergeSort, a, 0, n - 1);
//    TestSortFunc("HoarSort", HoarSort, a, 0, n - 1);
//    TestSortFunc("InsertSort", InsertSort, a, 0, n - 1);
//    TestSortFunc("InsertBinarySort", InsertBinarySort, a, 0, n - 1);
//    TestSortFunc("CountSort", CountSort, a, 0, n - 1);

    cout << "\n\n";

//    n = 100 * (n / 100);
//    vi b(n);
//    for (int i = 0; i < n; i += n / 100)
//    {
//        b[i] = rand() % INT16_MAX;
//        if (b[i] % 2 == 0)
//        {
//            for (int j = i + 1; j < i + n / 100; j++)
//                b[j] = b[j - 1] + rand() % INT8_MAX;
//        } else
//        {
//            for (int j = i + 1; j < i + n / 100; j++)
//                b[j] = b[j - 1] - rand() % INT8_MAX;
//        }
//    }
//
//    TestSortFunc("Timsort", TimSort, b, 0, n - 1);
//    TestSortFunc("STLSort", STlSort, b, 0, n - 1);
//    TestSortFunc("MergeSort", MergeSort, b, 0, n - 1);
//    TestSortFunc("FastMergeSort", FastMergeSort, b, 0, n - 1);
//    TestSortFunc("HoarSort", HoarSort, b, 0, n - 1);
//    TestSortFunc("InsertSort", InsertSort, b, 0, n - 1);

}
