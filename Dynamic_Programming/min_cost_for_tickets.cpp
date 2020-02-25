class Solution {
public:
    long int ans(long int dp[],int n){
        if(n<=0) return 0;
        return dp[n];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        long int dp[days[n-1]+1];
        for(int i=0;i<=days[n-1];i++){
            dp[i]=0;
        }
        int j=0;
        for(int i=1;i<=days[n-1];i++){
            if(i==days[j]){
                dp[i]=min(ans(dp,i-1)+costs[0],min(ans(dp,i-7)+costs[1],ans(dp,i-30)+costs[2]));
                j++;
            }
            else{
                dp[i]=dp[i-1];
            }
            cout<<dp[i]<<" ";
        }cout<<endl;
        return dp[days[n-1]];
    }
};