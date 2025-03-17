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
        void dfs(TreeNode* node, vector<int>& leaves){
            if(node == nullptr) return;
            if(node->left == nullptr && node->right == nullptr){
                leaves.push_back(node->val);
                return;
            }
            dfs(node->left, leaves);
            dfs(node->right, leaves);
        }
        bool vectorsAreEqual(vector<int>& left, vector<int>& right){
            int size = left.size();
            if(size != right.size()) return false;
            for(int i = 0; i < size; i++){
                if(left[i] != right[i]){
                    return false;
                }
            }
            return true;
        }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leavesLeft;
        vector<int> leavesRight;

        dfs(root1, leavesLeft);
        dfs(root2, leavesRight);
        return vectorsAreEqual(leavesLeft, leavesRight);
    }
};
