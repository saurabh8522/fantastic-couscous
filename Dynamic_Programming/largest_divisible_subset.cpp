class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        if(n==0){
            return res;
        }
        int dp[n],prev[n];
        sort(nums.begin(),nums.end());
        dp[0]=1;
        prev[0]=-1;
        int ma=1,pos=0;
        for(int i=1;i<n;i++){
            prev[i]=-1;
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                }
            }
            if(ma<dp[i]){
                ma=dp[i];
                pos=i;
            }
        }
        
            while(pos!=-1){
                res.push_back(nums[pos]);
                pos=prev[pos];
            }
            return res;
    }
};