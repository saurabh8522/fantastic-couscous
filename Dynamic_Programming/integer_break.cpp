class Solution {
public:
    int ans(int *dp,int n){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        cout<<n<<endl;
        for(int i=1;i<n;i++){
            int c=ans(dp,n-i);
            if(c<n-i){
                c=n-i;
            }
            dp[n]=max(dp[n],c*i);
            cout<<i<<" => "<<dp[n]<<endl;
        }
        cout<<n<<" ** "<<dp[n]<<endl;
        return dp[n];
    }
    int integerBreak(int n) {
        int dp[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=-1;
        }
        dp[0]=dp[1]=1;
        return ans(dp,n);
    }
};