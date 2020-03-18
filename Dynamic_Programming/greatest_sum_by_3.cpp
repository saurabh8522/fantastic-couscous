class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        int dp[n][3];
        memset(dp,0,sizeof(dp));
        dp[0][1]=dp[0][1]=dp[0][2]=0;
        dp[0][nums[0]%3]=nums[0];
        int ans=0;
        // cout<<dp[0][0]<<" "<<dp[0][1]<<" "<<dp[0][2]<<endl;
        for(int i=1;i<n;i++){
            if(nums[i]%3==0){
                dp[i][0]=dp[i-1][0]+nums[i];
                dp[i][1]=dp[i-1][1]>0?dp[i-1][1]+nums[i]:0;
                dp[i][2]=dp[i-1][2]>0?dp[i-1][2]+nums[i]:0;
            }
            else if(nums[i]%3==1){
                dp[i][0]=max(dp[i-1][0],dp[i-1][2]>0?dp[i-1][2]+nums[i]:0);
                dp[i][1]=max(dp[i-1][0]+nums[i],dp[i-1][1]);
                dp[i][2]=max(dp[i-1][2],dp[i-1][1]>0?dp[i-1][1]+nums[i]:0);
            }
            else{
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]>0?dp[i-1][1]+nums[i]:0);
                dp[i][1]=max(dp[i-1][1],dp[i-1][2]>0?dp[i-1][2]+nums[i]:0);
                dp[i][2]=max(dp[i-1][2],dp[i-1][0]+nums[i]);
            }
            // cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
            ans=max(ans,dp[i][0]);
        }
        return ans;
    }
};