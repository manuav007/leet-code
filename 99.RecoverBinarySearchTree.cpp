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
    TreeNode* first;
    TreeNode* middle;
    TreeNode* pres;
    
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        
        inorder(root->left);
        
        if (pres != nullptr && pres->val > root->val) {
            if (first == nullptr) {
                first = pres;
                middle = root;
            } else {
                middle = root;
            }
        }
        
        pres = root;
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        first = nullptr;
        middle = nullptr;
        pres = nullptr;
        
        inorder(root);
        swap(first->val, middle->val);
    }
};
