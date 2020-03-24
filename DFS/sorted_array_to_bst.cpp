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
    TreeNode* find(vector<int>&nums,int l,int r){
        if(l>r) return NULL;
        int mid=(l+r)>>1;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left=find(nums,l,mid-1);
        root->right=find(nums,mid+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return find(nums,0,nums.size()-1);
    }
};