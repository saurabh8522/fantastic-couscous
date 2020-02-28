class Solution {
public:
    bool check(vector<int>&nums,vector< vector<int> >&dp,int n,int req){
        if(req==0) return true;
        if(n<0||req<0){
            return false;
        }
        if(dp[n][req]!=-1){
            return dp[n][req];
        }
        // if(nums[n]==req){
        //     dp[n][req]=true;
        //     return true;
        // }
        bool ans1=check(nums,dp,n-1,req),ans2=check(nums,dp,n-1,req-nums[n]);
        dp[n][req]=ans1|ans2;
        return dp[n][req];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum&1){
            return false;
        }
        int req=sum/2;
        int n=nums.size();
        vector< vector<int> >dp;
        dp.resize(n);
        for(int i=0;i<n;i++){
            dp[i].resize(req+1);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=req;j++){
                dp[i][j]=-1;
            }
        }
        return check(nums,dp,n-1,req);
    }
};