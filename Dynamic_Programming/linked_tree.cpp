/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    map< pair< ListNode*, TreeNode* >,bool >mp;
    bool find(ListNode* head1, TreeNode* root,ListNode* head){
        bool ans=false;
        if(head1==NULL&&root==NULL) return true;
        if(root==NULL) return false;
        if(head1==NULL) return true;
       
        if(mp.find({head1,root})!=mp.end()){
            return mp[{head1,root}];
        }
        if(head1->val==root->val){
            ans=ans|find(head1->next,root->left,head)|find(head1->next,root->right,head);
        }
        ans=ans|find(head,root->left,head)|find(head,root->right,head);
        mp[{head1,root}]=ans;
        return ans;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return find(head,root,head);
    }
};