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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> unacademy;
        if(root==NULL) return unacademy;
        queue<TreeNode*> qu;
        bool choose = 1;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            vector<int> row(size);
            for(int i=0; i<size; i++){
                TreeNode* node = qu.front();
                qu.pop();
                int index = (choose)?i:size-i-1;
                row[index]=node->val;
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
            choose = !choose;
            unacademy.push_back(row);
        }
        return unacademy;
    }
};
