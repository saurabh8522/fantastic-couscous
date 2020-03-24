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
    // int ans=INT_MAX;
    int find(TreeNode* root){
        if(!root) return 0;
        int hl=find(root->left)+1;
        int hr=find(root->right)+1;
        // ans=min(ans,min(hl,hr));
        // cout<<hl<<" "<<hr<<" "<<root->val<<endl;
        int ans=min(hl,hr);
        if(!root->left^!root->right){
            ans=max(2,max(hl,hr));
        }
        return ans;
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        // if((!root->left||!root->right)&&!(!root->left&&!root->right)) return 2;
        return find(root);
        // return ans;
    }
};