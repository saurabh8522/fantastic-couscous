
class Solution {
public:
    long int dp[21][21][2];
    int find(int l,int r,int chance,vector<int>&nums){
        if(l>r) {
            return 0;
        }
        if(dp[l][r][chance]!=LONG_MAX){
            return dp[l][r][chance];
        }
        long int ans=dp[l][r][chance];
        if(chance==0){
            int ans1=find(l+1,r,1-chance,nums);
            int ans2=find(l,r-1,1-chance,nums);
            ans=max(ans1+nums[l],ans2+nums[r]);
            // cout<<ans1<<" "<<ans2<<" "<<nums[l]<<" "<<nums[r]<<" end \n";
        }
        else{
            int ans1=find(l+1,r,1-chance,nums);
            int ans2=find(l,r-1,1-chance,nums);
            ans=min(ans1-nums[l],ans2-nums[r]);
            // cout<<ans1<<" "<<ans2<<" "<<nums[l]<<" "<<nums[r]<<" end \n";
        }
        // cout<<"chance"<<" "<<"l "<<" "<<" r"<<"  "<<"ans"<<endl;
        // cout<<chance<<"      "<<l<<"   "<<r<<"  "<<ans<<endl;
        dp[l][r][chance]=ans;
        return dp[l][r][chance];
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        for(int i=0;i<21;i++){
            for
                (int j=0;j<21;j++){
                dp[i][j][0]=LONG_MAX;
                dp[i][j][1]=LONG_MAX;
            }
        }
        bool ans=(find(0,nums.size()-1,0,nums)>=0);
        return ans;
    }
};