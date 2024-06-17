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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, int pre_start, int pre_end,
                              vector<int>& inorder, int in_start, int in_end,
                              unordered_map<int, int>& mpp) {
        if (pre_start > pre_end || in_start > in_end) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int in_root = mpp[preorder[pre_start]];
        int num_left_nodes = in_root - in_start;
        root->left = buildTreeHelper(preorder, pre_start + 1, pre_start + num_left_nodes,
                                     inorder, in_start, in_root - 1, mpp);
        root->right = buildTreeHelper(preorder, pre_start + num_left_nodes + 1, pre_end,
                                      inorder, in_root + 1, in_end, mpp);
        return root;
    }
};
