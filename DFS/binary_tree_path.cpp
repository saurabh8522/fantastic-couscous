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
    vector<string>ans;
    void find(TreeNode* root,string str){
        if(!root) return;
        if(!root->left&&!root->right){
            // if(str[str.size()-1]=='>'){
            //     str.pop_back();
            //     str.pop_back();
            // }
            str+=to_string(root->val);
            ans.push_back(str);
            return ;
        }
        str+=to_string(root->val);
        str+="->";
        find(root->left,str);
        find(root->right,str);
        return ;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string str="";
        find(root,str);
        return ans;
    }
};