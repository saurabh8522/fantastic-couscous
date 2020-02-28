class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return n;
        }
        int dp[n][2];
        int ans=0;
       for(int i=0;i<n;i++){
           dp[i][0]=1;
           dp[i][1]=1;
       }
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    dp[i][1]=max(dp[i][1],dp[j][0]+1);
                }
                else if(nums[j]>nums[i]){
                    dp[i][0]=max(dp[i][0],dp[j][1]+1);
                }
            }
            ans=max(ans,max(dp[i][0],dp[i][1]));
        }
        return ans;
    }
};