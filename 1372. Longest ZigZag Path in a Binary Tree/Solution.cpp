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
    int m_maxLength = 0;

    void dfs(TreeNode* node, bool goingLeft, int length){
        if(node == nullptr) return;

        m_maxLength = max(m_maxLength, length);
        
        if(goingLeft){
            dfs(node->left, false, length + 1);
            dfs(node->right, true, 1);
        }
        else {
            dfs(node->right, true, length + 1);
            dfs(node->left, false, 1);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return m_maxLength;
    }
};
