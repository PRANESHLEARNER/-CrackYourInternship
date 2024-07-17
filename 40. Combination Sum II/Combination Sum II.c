/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void dfs(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int** res, int* combination, int start, int index) {
    if (target == 0) {
        res[*returnSize] = (int*)malloc(sizeof(int) * index);
        for (int i = 0; i < index; i++) {
            res[*returnSize][i] = combination[i];
        }
        (*returnColumnSizes)[*returnSize] = index;
        (*returnSize)++;
        return;
    }
    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue; // skip duplicates
        if (candidates[i] <= target) {
            combination[index] = candidates[i];
            dfs(candidates, candidatesSize, target - candidates[i], returnSize, returnColumnSizes, res, combination, i + 1, index + 1); // i + 1 because each number can be used only once
        }
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates, candidatesSize, sizeof(int), compare);
    int** res = (int**)malloc(sizeof(int*) * 150);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 150);
    int* combination = (int*)malloc(sizeof(int) * 150);
    *returnSize = 0;
    dfs(candidates, candidatesSize, target, returnSize, returnColumnSizes, res, combination, 0, 0);
    free(combination);
    return res;
}