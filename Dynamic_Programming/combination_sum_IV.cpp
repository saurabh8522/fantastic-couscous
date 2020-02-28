class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned long long dp[target+1];
        dp[0]=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=target)
                dp[nums[i]]=1;
        }
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j]<=i){
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};