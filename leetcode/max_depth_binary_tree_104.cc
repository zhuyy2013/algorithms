//Given a binary tree, find its maximum depth.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        int a = maxDepth(root->left), b = maxDepth(root->right);
        return a > b ? (a + 1) : (b + 1);
    }
};
