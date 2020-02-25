class Solution {
public:
    int numSquares(int n) {
        long int dp[n+5];
        for(int i=0;i<n+5;i++){
            dp[i]=INT_MAX;
        }
        dp[1]=1;
        dp[0]=1;
        dp[2]=2;
        // long int last=1;
        vector<int>pow;
        for(int i=1;i<=sqrt(n)+1;i++){
            pow.push_back(i*i);
        }
        for(int i=3;i<=n;i++){
            for(int j=0;j<pow.size()&&i>pow[j];j++){
                // cout<<j<<" "<<dp[j]
                dp[i]=min(dp[i],dp[pow[j]]+dp[i-pow[j]]);
                if(floor((float)sqrt(i))==ceil((float)sqrt(i))){
                    dp[i]=1;
                }
            }
            cout<<i<<" "<<dp[i]<<endl;
        }
        return dp[n];
    }
};