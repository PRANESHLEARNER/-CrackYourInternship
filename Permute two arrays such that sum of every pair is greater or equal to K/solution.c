// C program to check whether permutation of two
// arrays satisfy the condition a[i] + b[i] >= k.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort for Increasing Order
int cmpfunc1(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

// Compare function for qsort for decreasing Order
int cmpfunc2(const void* a, const void* b)
{
    return (*(int*)b - *(int*)a);
}

// Check whether any permutation exists which
// satisfy the condition.
bool isPossible(int a[], int b[], int n, int k)
{
    // Sort the array a[] in decreasing order.
    qsort(a, n, sizeof(int), cmpfunc1);

    // Sort the array b[] in increasing order.
    qsort(b, n, sizeof(int), cmpfunc2);

    // Checking condition on each index.
    for (int i = 0; i < n; i++)
        if (a[i] + b[i] < k)
            return false;

    return true;
}

// Driven Program
int main()
{
    int a[] = { 2, 1, 3 };
    int b[] = { 7, 8, 9 };
    int k = 10;
    int n = sizeof(a) / sizeof(a[0]);

    isPossible(a, b, n, k) ? printf("Yes") : printf("No");
    return 0;
}
