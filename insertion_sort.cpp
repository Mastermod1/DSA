#include <cassert>
#include <iostream>

void insertion_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = arr[i];
        int minInd = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minInd = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[minInd];
        arr[minInd] = tmp;
    }
}

bool is_sorted(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i-1])
            return false;
    }
    return true;
}

int main()
{
    int reversed[] = {8,7,6,5,4,3,2,1};
    insertion_sort(reversed, 8);
    assert(is_sorted(reversed, 8));

    int ordered[] = {1,2,3,4,5,6,7,8};
    insertion_sort(ordered, 8);
    assert(is_sorted(ordered, 8));

    int random[] = {8,1,7,2,6,3,4,5};
    insertion_sort(random, 8);
    assert(is_sorted(random, 8));
}
