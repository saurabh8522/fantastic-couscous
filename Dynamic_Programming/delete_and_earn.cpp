class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        sort(nums.begin(),nums.end());
        int dp[10001],freq[20001];
        memset(dp,0,sizeof(dp));
        memset(freq,0,sizeof(freq));
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        dp[1]=freq[1];
        int ans=0;
        for(int i=2;i<=nums[nums.size()-1];i++){
            dp[i]=max(dp[i-1],dp[i-2]+freq[i]*i);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};