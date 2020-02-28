class Solution {
public:
    long int ans(vector< vector<long int> >&dp,int l,int r){
        if(l>=r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        long int an=INT_MAX;
        for(long int i=l;i<=r;i++){
            an=min(an,i+max(ans(dp,l,i-1),ans(dp,i+1,r)));
        }
        dp[l][r]=an;
        return an;
    }
    int getMoneyAmount(int n) {
        int l=1,r=n;
        vector< vector<long int> >dp;
        dp.resize(n+1);
        for(int i=1;i<=n;i++){
            dp[i].resize(n+1);
        }
       for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
               dp[i][j]=-1;
           }
       }
        return ans(dp,1,n);
    }
};