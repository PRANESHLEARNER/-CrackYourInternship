/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// Function to swap two elements
void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

// Function to compare two elements for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int start, int** res, int* returnSize) {
    if (start == numsSize) {
        res[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        memcpy(res[*returnSize], nums, numsSize * sizeof(int));
        (*returnSize)++;
        return;
    }
    for (int i = start; i < numsSize; i++) {
        // Skip duplicates
        int j = i - 1;
        while (j >= start && nums[j] != nums[i]) j--;
        if (j != start - 1) continue;
        
        swap(nums, start, i);
        backtrack(nums, numsSize, start + 1, res, returnSize);
        swap(nums, start, i); // backtrack
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare); // sort the array first
    int** res = (int**)malloc(5000 * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(5000 * sizeof(int));
    for (int i = 0; i < 5000; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    backtrack(nums, numsSize, 0, res, returnSize);
    return res;
}