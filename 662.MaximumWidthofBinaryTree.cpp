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
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int ans = 0;
        queue<pair<TreeNode*, int>> qu;
        qu.push({root, 0});
        
        while (!qu.empty()) {
            int minIndex = qu.front().second;
            int size = qu.size();
            int first, last;
            for (int i = 0; i < size; ++i) {
                long long curIndex = qu.front().second - minIndex; 
                TreeNode* node = qu.front().first;
                qu.pop();
                
                if (i == 0) first = curIndex;
                if (i == size - 1) last = curIndex;
                
                if (node->left) {
                    qu.push({node->left, curIndex * 2 + 1});
                }
                if (node->right) {
                    qu.push({node->right, curIndex * 2 + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        
        return ans;
    }
};
