/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL) return 0;
        int l=0;
        vector< vector<Node*> >v(1);
        v[0].push_back(root);
        while(!v[l].empty()){
            v.push_back(vector<Node*>());
            for(auto n : v[l]){
                for(auto t : n->children){
                    v[l+1].push_back(t);
                }
            }
            l++;
        }
        return v.size()-1;
    }
};