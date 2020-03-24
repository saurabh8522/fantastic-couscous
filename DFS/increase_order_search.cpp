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
    vector<int>nodes;
    void inorder(TreeNode* root){
        if(!root) return ;
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
        return ;
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        TreeNode* ans = new TreeNode(nodes[0]);
        TreeNode*ans1=ans;
        for(int i=1;i<nodes.size();i++){
            TreeNode* a = new TreeNode(nodes[i]);
            ans1->right=a;
            ans1=ans1->right;
        }
        return ans;
    }
};