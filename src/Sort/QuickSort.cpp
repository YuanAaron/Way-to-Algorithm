#include "QuickSort.hpp"
#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;


auto AssertNotAscendingOrder(int s[MAX], int n) -> void
{
    bool res = true;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i + 1]) {
            res = false;
            break;
        }
    }
    assert(!res);
}
auto AssertAscendingOrder(int s[MAX], int n) -> void
{
    bool res = true;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i + 1]) {
            res = false;
            break;
        }
    }
    assert(res);
}
auto AssertQuickSort(int s[MAX], int n) -> void
{
    AssertNotAscendingOrder(s, n);
    QuickSort(s, 0, n);
    AssertAscendingOrder(s, n);
}


#define TEST_MAX 1024

auto main(void) -> int
{
    int s[MAX];

    for (int i = 0; i < TEST_MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            s[j] = rand() % TEST_MAX;
        }
        AssertQuickSort(s, MAX);
    }

    return 0;
}

