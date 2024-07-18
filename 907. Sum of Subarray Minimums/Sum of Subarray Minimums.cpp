class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> leftStack, rightStack;

        // Compute left array
        for (int i = 0; i < n; ++i) {
            while (!leftStack.empty() && arr[i] <= arr[leftStack.top()]) {
                leftStack.pop();
            }
            left[i] = leftStack.empty() ? i + 1 : i - leftStack.top();
            leftStack.push(i);
        }

        // Compute right array
        for (int i = n - 1; i >= 0; --i) {
            while (!rightStack.empty() && arr[i] < arr[rightStack.top()]) {
                rightStack.pop();
            }
            right[i] = rightStack.empty() ? n - i : rightStack.top() - i;
            rightStack.push(i);
        }

        // Compute the result
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result = (result + (long long)arr[i] * left[i] * right[i]) % MOD;
        }

        return result;
    }
};