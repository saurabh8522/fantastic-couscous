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
    int l,r,ans;
    pair<int,int> find(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        // cout<<root->val<<endl;
        pair<int,int>p1=find(root->left);
        pair<int,int>p2=find(root->right);
        pair<int,int> p;
        p.first=p1.second+1;
        p.second=p2.first+1;
        ans=max(ans,max(p.first,p.second));
        return p;
    }
    int longestZigZag(TreeNode* root) {
        if(root==NULL) return 0;
        find(root);
        return ans-1;
    }
};