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
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> queue({root});
        int maximumSum = INT_MIN;
        int maximumSumLevel = 0;
        int currentLevel = 0;

        while(!queue.empty()){
            currentLevel++;    
            int queueSize = queue.size();
            int currentLevelSum = 0;
            
            for(int i = 0; i < queueSize;i++){
                TreeNode* currentQueueItem = queue.front();
                currentLevelSum += currentQueueItem->val;
                queue.pop();

                if(currentQueueItem->left) queue.push(currentQueueItem->left);
                if(currentQueueItem->right) queue.push(currentQueueItem->right);
            }

            if(currentLevelSum > maximumSum){
                maximumSum = currentLevelSum;
                maximumSumLevel = currentLevel;
            }
        }
        return maximumSumLevel;
    }
};
