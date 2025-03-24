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
        void VerifyIfFoundNode(TreeNode*& parent, TreeNode*& node, TreeNode*& parentPointer, int value){
            if(node->val == value) {
                parentPointer = parent;
            }
        }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> queue({root});
        
        TreeNode* xParent = nullptr;
        TreeNode* yParent = nullptr;

        while(!queue.empty()){
            int queueSize = queue.size();
            TreeNode* current = nullptr;

            for(int i = 0; i < queueSize; i++){
                current = queue.front();
                queue.pop();

                if(current->left) {
                    queue.push(current->left);
                    VerifyIfFoundNode(current, current->left, xParent, x);
                    VerifyIfFoundNode(current, current->left, yParent, y);
                };

                if(current->right) {
                    queue.push(current->right);
                    VerifyIfFoundNode(current, current->right, xParent, x);
                    VerifyIfFoundNode(current, current->right, yParent, y);
                }
            }

            if (xParent && yParent) {
                return xParent != yParent;
            }

            if (xParent || yParent) {
                return false;
            }
        }
        return false;
    }
};
