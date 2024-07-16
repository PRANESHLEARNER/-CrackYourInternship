class Solution:
    def majorityElement(self, nums):
        counts = {}
        for num in nums:
            if num not in counts:
                counts[num] = 0
            counts[num] += 1
            if counts[num] > len(nums) // 2:
                return num