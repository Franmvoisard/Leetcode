/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:  
        int dfs(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int> &prefixSumFrequencyMap){
            if(node == nullptr) return 0;

            currentSum += node->val;
            int possiblePaths = prefixSumFrequencyMap[currentSum - targetSum];
            prefixSumFrequencyMap[currentSum]++;
            possiblePaths += dfs(node->left, currentSum, targetSum, prefixSumFrequencyMap);
            possiblePaths += dfs(node->right, currentSum, targetSum, prefixSumFrequencyMap);
            prefixSumFrequencyMap[currentSum]--;
            return possiblePaths;
        }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSumFrequencyCount;
        prefixSumFrequencyCount[0] = 1;
        return dfs(root, 0, targetSum, prefixSumFrequencyCount);
    }
};
