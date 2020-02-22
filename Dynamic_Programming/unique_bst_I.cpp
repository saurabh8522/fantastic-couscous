int ans(int n,int dp[]){
    if(dp[n]) return dp[n];
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=ans(i-1,dp)*ans(n-i,dp);
    }
    dp[n]=sum;
    return sum;
}
int numTrees(int n){
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=dp[1]=1;
    return ans(n,dp);
}