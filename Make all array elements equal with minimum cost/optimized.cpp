#include <bits/stdc++.h>
using namespace std;

// This function assumes that a[] is
// sorted. If a[] is not sorted, we need
// to sort it first.
int minCostToMakeElementEqual(int a[], int n)
{

	// If there are odd elements, we choose
	// middle element
	int y;
	if (n % 2 == 1)
		y = a[n / 2];

	// If there are even elements, then we choose
	// the average of middle two.
	else
		y = (a[n / 2] + a[(n - 2) / 2]) / 2;

	// After deciding the final value, find the
	// result.
	int s = 0;
	for(int i = 0; i < n; i++)
		s += abs(a[i] - y);
		
	return s;
}

// Driver code
int main()
{
	int a[] = { 1, 100, 101 };
	int n = sizeof(a) / sizeof(a[0]);
	sort(a, a + n);

	cout << (minCostToMakeElementEqual(a, n));
}

// This code is contributed by chitranayal
