#include "my_sort.h"
#include "Timsort.hpp"
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

#define vi vector<int>
#define all(v) v.begin(), v.end()
#define vpii vector<pair<int, int>>
#define CIN                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl "\n"

void TestSortFunc(string sortName, void sortFunc(vi &a, int l, int r), vi &a, int l, int r)
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
}
