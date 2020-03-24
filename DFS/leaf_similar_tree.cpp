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
    void dfs(TreeNode* root,vector<int>&v){
        if(!root) return ;
        if(root->left==NULL&&root->right==NULL){
            v.push_back(root->val);return;
        }
        // if(root->right==NULL){
        //     v.push_back(root->val);return ;
        // }
        dfs(root->left,v);
        dfs(root->right,v);
        return ;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        dfs(root1,v1);dfs(root2,v2);
        // for(int i=0;i<v1.size();i++){
        //     cout<<v1[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<v2.size();i++){
        //     cout<<v2[i]<<" ";
        // }
        // cout<<endl;
        return v1==v2;
    }
};