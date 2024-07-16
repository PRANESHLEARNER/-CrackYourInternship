class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> indexStack;
        heights.push_back(0); // Add a sentinel value to pop out remaining bars
        for (int i = 0; i < heights.size(); ++i) {
            while (!indexStack.empty() && heights[i] < heights[indexStack.top()]) {
                int h = heights[indexStack.top()];
                indexStack.pop();
                int width = indexStack.empty() ? i : i - indexStack.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            indexStack.push(i);
        }
        return maxArea;
    }
};