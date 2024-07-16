void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int index1 = m - 1; // Index of the last element in nums1
    int index2 = n - 1; // Index of the last element in nums2
    int mergedIndex = m + n - 1; // Index of the last element in the merged array

    // Merge nums1 and nums2 from the end
    while (index1 >= 0 && index2 >= 0) {
        if (nums1[index1] > nums2[index2]) {
            nums1[mergedIndex] = nums1[index1];
            index1--;
        } else {
            nums1[mergedIndex] = nums2[index2];
            index2--;
        }
        mergedIndex--;
    }

    // If there are remaining elements in nums2, copy them to nums1
    while (index2 >= 0) {
        nums1[mergedIndex] = nums2[index2];
        index2--;
        mergedIndex--;
    }
}