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
    pair<TreeNode*, int> findLCA(TreeNode*& node){
        if(node == nullptr) return std::make_pair(nullptr, 0);
        
        auto [leftLCA, leftHeight] = findLCA(node->left);
        auto [rightLCA, rightHeight] = findLCA(node->right);
        
        if(leftHeight == rightHeight) return std::make_pair(node, leftHeight + 1);
        else if(leftHeight > rightHeight) return std::make_pair(leftLCA, leftHeight + 1);
        else return std::make_pair (rightLCA, rightHeight + 1);
    };

public:
    TreeNode* lcaDeepestLeaves(TreeNode*& root) {
        
        auto [lca, height] = findLCA(root);
        return lca;
    }
};
