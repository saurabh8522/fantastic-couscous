class Solution {
public:
    int dp[501][501];
    int find(int l,int r,vector<int>&nums){
        if(l>r) return 0;
        // if(l==r) return dp[l][r]=nums[l];
        int & ans = dp[l][r];
        if(ans!=-1) return ans;
        ans=0;
        // cout<<l<<" "<<r<<endl;
        for(int k=l;k<=r;k++){
            int left = (0==l)?1:nums[l-1];
            int right = (nums.size()-1==r)?1:nums[r+1];
            ans=max(ans,find(l,k-1,nums)+find(k+1,r,nums)+left*nums[k]*right);
        }
        // cout<<l<<" * "<<r<<" * "<<ans<<endl;
        return ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        
        int ans =find(0,nums.size()-1,nums);
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<nums.size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};