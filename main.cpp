#include "MiniSort.h"
#include "Timsort.hpp"
#include "MergeSort.h"
#include "MiniSort.h"

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
            cout << sortName << " Error";
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
    vi a(n);
    for (int i = 0; i < n; ++i)
        a[i] = rand() % INT32_MAX;

    TestSortFunc("Timsort", TimSort, a, 0, n - 1);
    TestSortFunc("STLSort", STlSort, a, 0, n - 1);
    TestSortFunc("MergeSort", MergeSort, a, 0, n - 1);
    TestSortFunc("FastMergeSort", FastMergeSort, a, 0, n - 1);
    TestSortFunc("HoarSort", HoarSort, a, 0, n - 1);
    TestSortFunc("InsertSort", InsertSort, a, 0, n - 1);
}
