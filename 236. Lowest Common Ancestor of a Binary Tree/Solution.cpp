/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
            TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q){
            if(node == nullptr) return nullptr;

            if(node->val == p-> val || node->val == q-> val) return node;

            TreeNode* left = dfs(node->left, p, q);
            TreeNode* right = dfs(node->right, p, q);

            if(left && right){
                return node;
            }
            else {
                if(left != nullptr) return left;
                else return right;
            }
            return node;
        }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p , q);
    }
};
