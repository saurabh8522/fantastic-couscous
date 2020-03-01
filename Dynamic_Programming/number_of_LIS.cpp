class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return n;
        vector<int>dp(n,1);
        vector<int>count(n,1);
        int ans=1;
        vector<int>prev[n];
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    if(dp[i]<dp[j]+1){
                        count[i]=count[j];
                        dp[i]=dp[j]+1;
                        ans=max(ans,dp[i]);
                    }
                    else if(dp[i]==dp[j]+1){
                        count[i]+=count[j];
                    }
                }
            }
        }
        if(ans==1){
            return n;
        }
        int c=0;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==ans){
                c+=count[i];
            }
        }
        return c;
    }
};