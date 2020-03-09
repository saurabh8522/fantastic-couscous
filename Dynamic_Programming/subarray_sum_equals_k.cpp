class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        int ans=0,s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(s==k) ans++;
            if(mp.find(s-k)!=mp.end()){
                ans+=mp[s-k];
            }
            mp[s]++;
        }
        return ans;
    }
};