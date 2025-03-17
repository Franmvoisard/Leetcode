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
    inline void dfs(TreeNode* node, int currentPathMaximum, int& goodNodes){
        if(node == nullptr) return;
        if(node->val >= currentPathMaximum){
            goodNodes++;
            currentPathMaximum = max(currentPathMaximum, node->val);
        }
        dfs(node->left, currentPathMaximum, goodNodes);
        dfs(node->right, currentPathMaximum, goodNodes);
    }
public:
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int result = 0;
        dfs(root, root->val, result);
        return result;
    }
};

auto init = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
};
