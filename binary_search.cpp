#include <cassert>
#include <iostream>
#include <optional>

std::optional<int> binary_search(int sorted_arr[], int size, int searched)
{
    int s = 0;
    int e = size - 1;
    while(s <= e)
    {
        int mid = (e + s)/2;
        if (sorted_arr[mid] == searched)
            return mid;

        if (sorted_arr[mid] < searched)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return {};
}

int main()
{
    int a[] = {1, 2, 4, 7, 8, 10, 15, 20, 30, 31, 32, 33};
    assert(binary_search(a, 12, 1) == 0);
    assert(binary_search(a, 12, 2) == 1);
    assert(binary_search(a, 12, 4) == 2);
    assert(binary_search(a, 12, 7) == 3);
    assert(binary_search(a, 12, 8) == 4);
    assert(binary_search(a, 12, 10) == 5);
    assert(binary_search(a, 12, 15) == 6);
    assert(binary_search(a, 12, 20) == 7);
    assert(binary_search(a, 12, 30) == 8);
    assert(binary_search(a, 12, 31) == 9);
    assert(binary_search(a, 12, 32) == 10);
    assert(binary_search(a, 12, 33) == 11);
    assert(binary_search(a, 12, 34) == std::optional<int>());
    assert(binary_search(a, 12, -1) == std::optional<int>());
}
