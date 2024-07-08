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
    bool isSymmetric(TreeNode* root) {
        return root == NULL || recu(root->left, root->right);
    }

    bool recu(TreeNode* lef, TreeNode* rig) {
        if (lef == NULL || rig == NULL) return lef == rig;
        if (lef->val != rig->val) return false;
        return recu(lef->left, rig->right) && recu(lef->right, rig->left);
    }
};
