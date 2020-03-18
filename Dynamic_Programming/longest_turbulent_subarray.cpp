class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size()<2) return A.size();
        int dp[A.size()][2];
        dp[0][0]=dp[0][1]=1;
        int ans=1;
        for(int i=1;i<A.size();i++){
            // cout<<i<<
            if(A[i]>A[i-1]){
                dp[i][1]=dp[i-1][0]+1;
                dp[i][0]=1;
            }
            else if(A[i]<A[i-1]){
                dp[i][0]=dp[i-1][1]+1;
                dp[i][1]=1;
            }
            else{
                dp[i][0]=dp[i][1]=1;
            }
            ans=max(ans,max(dp[i][0],dp[i][1]));
            // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }
        return ans;
    }
};