#include <iostream>
#include <algorithm> // for sort function
using namespace std;

// Function to calculate the minimum cost to break the board into m * n squares
int minimumCostOfBreaking(int horizontalCost[], int verticalCost[], int m, int n) {
    int totalCost = 0;

    // Sort the horizontal cost array in descending order
    sort(horizontalCost, horizontalCost + m, greater<int>());

    // Sort the vertical cost array in descending order
    sort(verticalCost, verticalCost + n, greater<int>());

    int horizontalParts = 1, verticalParts = 1; // Initialize current width as 1

    int i = 0, j = 0;
    while (i < m && j < n) {
        if (horizontalCost[i] > verticalCost[j]) {
            // Add cost of the current horizontal part
            totalCost += horizontalCost[i] * verticalParts;

            // Increase the current horizontal part count by 1
            horizontalParts++;
            i++;
        } else {
            // Add cost of the current vertical part
            totalCost += verticalCost[j] * horizontalParts;

            // Increase the current vertical part count by 1
            verticalParts++;
            j++;
        }
    }

    // Loop for the remaining horizontal array
    int remainingHorizontalCost = 0;
    while (i < m)
        remainingHorizontalCost += horizontalCost[i++];
    totalCost += remainingHorizontalCost * verticalParts;

    // Loop for the remaining vertical array
    int remainingVerticalCost = 0;
    while (j < n)
        remainingVerticalCost += verticalCost[j++];
    totalCost += remainingVerticalCost * horizontalParts;

    return totalCost;
}