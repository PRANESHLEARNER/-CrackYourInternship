int findDuplicate(int* nums, int numsSize) {
    // Phase 1: Using Floyd's Tortoise and Hare algorithm to find intersection point
    int tortoise = nums[0];
    int hare = nums[0];
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);
    
    // Phase 2: Find the entrance to the cycle
    tortoise = nums[0];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    
    return hare;
}
