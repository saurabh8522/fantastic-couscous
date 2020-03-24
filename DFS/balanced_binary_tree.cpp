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
    bool ans=true;
    int find(TreeNode* root){
        if(!root) return 0;
        int hl=find(root->left)+1;
        int hr=find(root->right)+1;
        ans=ans&(abs(hl-hr)<=1)?true:false;
        // cout<<hl<<" "<<hr<<" "<<root->val<<endl;
        return max(hl,hr);
    }
    bool isBalanced(TreeNode* root) {
        find(root);
        return ans;
    }
};