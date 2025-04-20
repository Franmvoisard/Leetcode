// Time: O(n)
// Space: O(n) 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stack;
        vector<int> result(n, 0);
        stack.push(n - 1);

        for (int i = n - 2; i >= 0; i--) {
            int currentTemp = temperatures[i];

            while (!stack.empty() && temperatures[stack.top()] <= currentTemp) {
                stack.pop();
            }
            result[i] = stack.empty() ? 0 :  stack.top() - i;
            stack.push(i);
        }
        return result;
    }
};
