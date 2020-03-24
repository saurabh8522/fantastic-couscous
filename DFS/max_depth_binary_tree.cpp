/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int find(TreeNode* root){
        if(!root) return 0;
        return max(find(root->left)+1,find(root->right)+1);
    }
    int maxDepth(TreeNode* root) {
        return find(root);
    }
};