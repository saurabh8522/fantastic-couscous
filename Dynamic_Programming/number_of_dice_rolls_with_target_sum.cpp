#define MOD 1000000007
class Solution {
public:
    long int dp[31][1001];
    long int find(int d,int f,int target){
        if(d==0&&target!=0) return 0;
        if(target<0) return 0;
        if(target==0&&d!=0) return 0;
        if(target==0) return 1;
        long int &ans=dp[d][target];
        if(ans!=-1) return ans;
        ans=0;
        for(int i=1;i<=f;i++){
            ans=ans+find(d-1,f,target-i);
            ans=ans%MOD;
        }
        return (ans%MOD);
    }
    int numRollsToTarget(int d, int f, int target) {
        memset(dp,-1,sizeof(dp));
        return find(d,f,target);
    }
};