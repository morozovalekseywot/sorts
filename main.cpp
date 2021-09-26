#include "MiniSort.h"
#include "Timsort.hpp"
#include "MergeSort.h"
#include "ISorter.h"
//#include "C:\Users\Diablo\CLionProjects\Cstring\Sequence.hpp"
//#include "C:\Users\Diablo\CLionProjects\Cstring\Array_Sequence.hpp"
//#include "C:\Users\Diablo\CLionProjects\Cstring\Linked_List_Sequence.hpp"
#include "generate.h"
#include <fstream>
#include <cstdlib>


#define CIN                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

template<typename T>
void TestSortFunc(string sortName, void (*sortFunc)(vector<T> &, int, int), vector<T> &a, int l, int r)
{
    vt b = a;
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

template<typename T>
void BenchSortFunc(string path, string sortName, void (*sortFunc)(vector<T> &, int, int), vector<T> &a, int n)
{
//    string path = "../graphics/real/";
    path.append(sortName.begin(), sortName.end());
    path.append(".txt");
    ofstream file(path, ios_base::trunc);

    for (int i = n / 200; i <= n; i += n / 200)
    {
        vector<T> b(a.begin(), a.begin() + i);

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

template<typename T>
void Bench(string path, vt &a, int n)
{
    BenchSortFunc(path, "Timsort", TimSort, a, n);
    BenchSortFunc(path, "HoarSort", HoarSort, a, n);
    BenchSortFunc(path, "MergeSort", MergeSort, a, n);
    BenchSortFunc(path, "FastMergeSort", FastMergeSort, a, n);
    BenchSortFunc(path, "STLSort", STlSort, a, n);
//    BenchSortFunc("CountSort", CountSort, a, n);
}

template<typename T>
void Bench2(string path, vt &a, int n)
{
    BenchSortFunc(path, "InsertBinarySort", InsertBinarySort, a, n);
    BenchSortFunc(path, "InsertSort", InsertSort, a, n);
}

int main()
{
    int n;
    srand(time(NULL));
    //cin >> n;
    n = 1000000;
    ArrayGenerator generator(n);
    vi randomArray = generator.GenerateRandomArray();
    vi sortedArray = generator.GenerateSortedArray();
    vi reverseArray = generator.GenerateReverseArray();
    vi swapArray = generator.GenerateSwapArray();

    string pathRandom = "../graphics/random/";
    string pathSorted = "../graphics/sorted/";
    string pathReverse = "../graphics/reverse/";
    string pathSwap = "../graphics/swap/";

    Bench(pathRandom, randomArray, n);
    Bench(pathSorted, sortedArray, n);
    Bench(pathReverse, reverseArray, n);
    Bench(pathSwap, swapArray, n);

    Bench2(pathRandom, randomArray, n / 50);

//    TestSortFunc("STLSort", STlSort, randomArray, 0, n - 1);
//    TestSortFunc("MergeSort", MergeSort, randomArray, 0, n - 1);
//    TestSortFunc("FastMergeSort", FastMergeSort, randomArray, 0, n - 1);
//    TestSortFunc("HoarSort", HoarSort, randomArray, 0, n - 1);
//    TestSortFunc("InsertSort", InsertSort, randomArray, 0, n - 1);
//    TestSortFunc("InsertBinarySort", InsertBinarySort, randomArray, 0, n - 1);
//    TestSortFunc("CountSort", CountSort, randomArray, 0, n - 1);

}
