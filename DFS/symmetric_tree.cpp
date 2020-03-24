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
    bool find(TreeNode* root1,TreeNode* root2){
        if(!root1&&!root2) return true;
        if(!root1||!root2) return false;
        if(root1->val==root2->val){
            return find(root1->left,root2->right)&&find(root1->right,root2->left);
        }
        return false;
    } 
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return find(root,root);
    }
};