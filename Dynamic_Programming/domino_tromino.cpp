class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int dp[A.size()][2];
        dp[0][0]=0,dp[0][1]=1;
        for(int i=1;i<A.size();i++){
            if(A[i]>A[i-1]&&B[i]>B[i-1]&&A[i]>B[i-1]&&B[i]>A[i-1]){
                dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
                dp[i][1]=dp[i][0]+1;
            }
            else if(A[i]>A[i-1]&&B[i]>B[i-1]){
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1]+1;
            }
            else{
                dp[i][0]=dp[i-1][1];
                dp[i][1]=dp[i-1][0]+1;
            }
        }
        return min(dp[A.size()-1][1],dp[A.size()-1][0]);
    }
};