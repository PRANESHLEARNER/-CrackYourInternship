int maxArea(int* height, int heightSize) {
    int max_water = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right) {
        int width = right - left;
        int current_water = width * (height[left] < height[right] ? height[left] : height[right]);
        max_water = current_water > max_water ? current_water : max_water;

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_water;
}