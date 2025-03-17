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
        void dfsLeft(TreeNode* node, queue<int> &queue){
            if(node == nullptr) return;
            if(node -> left == nullptr && node -> right == nullptr) {
                queue.push(node->val);
            }
            dfsLeft(node->left, queue);
            dfsLeft(node->right, queue);
        }

        void dfsRight(TreeNode* node, queue<int> &queue, bool &areLeafSimilar){
            if(node == nullptr || areLeafSimilar == false ) return;
            if(node -> left == nullptr && node -> right == nullptr) {
                if(node->val != queue.front()){
                    areLeafSimilar = false;
                    queue.pop();
                    return;
                }
                else {
                    queue.pop();
                }
            }
            dfsRight(node->left, queue, areLeafSimilar);
            dfsRight(node->right, queue, areLeafSimilar);
        }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        queue<int> dfsqueue;
        bool result = true;
        dfsLeft(root1, dfsqueue);
        dfsRight(root2, dfsqueue, result);
        return result && dfsqueue.empty();
    }
};
