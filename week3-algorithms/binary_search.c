#include <stdio.h>
#include <stdlib.h>

/* The Java-like encapsulation Pattern
 * bundle the array pointer and its length into a single structure.
 * This prevents the "Array Decay" problem where C loses the size of an
 * array when passing it to a function.
 */
typedef struct
{
    int *data;
    int length; // explicitly store how many elements the array holds
} my_array;

int bs(my_array arr, int target);

int main(void)
{
    int raw_arr[] = {1, 3, 5, 7, 9};

    my_array arr;
    arr.data = raw_arr;

    // calculate thelength in the same scope where raw_array is defined
    // (total bytes of the array) / (total bytes of one element) = number of elements
    arr.length = sizeof(raw_arr) / sizeof(raw_arr[0]);

    printf("target is at index %i\n", bs(arr, 3));
    printf("%i\n", bs(arr, -10));
    return 0;
}

int bs(my_array array, int target)
{
    int first = 0;
    int last = array.length - 1;

    while (first <= last)
    {
        // C performs division before addition
        int mid = (first + last) / 2;
        int guess = array.data[mid];

        if (target == guess)
        {
            return mid;
        }

        if (guess > target)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
    return -1;
}
