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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        find(root,maxi);
        return maxi;
    }
    int find(TreeNode* root, int& maxi){
        if(!root){
            return 0;
        }
        int lh = find(root->left, maxi);
        int rh = find(root->right, maxi);
        maxi = max(maxi, lh+rh);
        return 1 + max(lh, rh);
    }
};
