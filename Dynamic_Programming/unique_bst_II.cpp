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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            vector<TreeNode *>v;
            return v;
        }
        return gen(1,n);
    }
    vector<TreeNode*>gen(int first,int last){
        vector<TreeNode*>result;
        if(first>last){
            result.push_back(NULL);
            return result;
        }
        for(int i=first;i<=last;i++){
            vector<TreeNode*>left=gen(first,i-1);
            vector<TreeNode*>right=gen(i+1,last);
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left=left[j];
                    root->right=right[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};