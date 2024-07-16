int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0)
            res[(*returnSize)++] = abs(nums[i]);
        else
            nums[index] = -nums[index];
    }
    return res;
}