class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;
        if(n==2) return  91;
        long long ans=81;
        long long dp[n+1];
        dp[0]=1;dp[1]=10;dp[2]=91;
        int i=2;
        while(i<n&&i<11){
            i++;
            ans=ans*(11-i);
            dp[i]=dp[i-1]+ans;
            
        }
        if(n>=11){
            dp[11];
        }
        return dp[n];
    }
};