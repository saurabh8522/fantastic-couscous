class Solution {
public:
    double new21Game(int N, int K, int W) {
        long double dp[N+W+1];
        memset(dp,0,sizeof(dp));
        for(int i=K;i<=N;i++){
            dp[i]=1.0;
        }
        long double sum=(long double)min(N-K+1,W);
        // cout<<sum<<endl;
        for(int i=K-1;i>=0;i--){
            dp[i]=sum/(long double)W;
            sum=sum+dp[i]-dp[i+W];
            // cout<<dp[i]<<" "<<sum<<endl;
        }
        return dp[0];
    }
};

