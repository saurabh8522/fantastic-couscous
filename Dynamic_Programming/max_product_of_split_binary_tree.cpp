/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define MOD 1000000007
class Solution {
public:
    long long int ans=0,sum=0;
    long long int find(TreeNode* root){
        if(root==NULL) return 0;
        long long int ans1=find(root->left);
        long long int ans2=find(root->right);
        // cout<<root->val<<" "<<ans1<<" "<<ans2<<endl;
        long long int ans3=(ans1*(sum-ans1));
        long long int ans4=(ans2*(sum-ans2));
        // long long int ans3=ans1*(sum-ans1);
        // long long int ans4=ans2*(sum-ans2);
        ans=max(ans,max(ans3,ans4));
        ans=ans;
        // cout<<root->val<<" "<<ans<<endl;
        return (ans1+ans2+(long long int)root->val);
    }
    void find1(TreeNode* root){
        if(root==NULL) return ;
        sum+=(long long int)root->val;
        find1(root->left);
        find1(root->right);
    }
    int maxProduct(TreeNode* root) {
        // int sum=0;
        find1(root);
        // cout<<sum<<endl;
        find(root);
        return (int)(ans%MOD);
    }
};