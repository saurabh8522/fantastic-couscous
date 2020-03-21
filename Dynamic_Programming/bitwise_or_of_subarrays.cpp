class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int>ans;
        unordered_set<int>ans1;
        unordered_set<int>ans2;
        ans1.insert(0);
        for(int i=0;i<A.size();i++){
            ans2.clear();
            for(auto it : ans1){
                ans2.insert(it|A[i]);
                // cout<<it<<" "<<i<<endl;
            }
            ans2.insert(A[i]);
            ans1=ans2;
            // ans1.insert(0);
            for(auto it : ans2){
                ans.insert(it);
                // cout<<it<<endl;
            }
        }
        return ans.size();
    }
};