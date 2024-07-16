typedef struct {
    int* sum;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = malloc(sizeof(NumArray));
    obj->sum = malloc((numsSize + 1) * sizeof(int));
    obj->sum[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        obj->sum[i + 1] = obj->sum[i] + nums[i];
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->sum[right + 1] - obj->sum[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->sum);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 * numArrayFree(obj);
*/