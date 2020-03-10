#define MOD 1000000007
class Solution {
public:
     long int dp[1002][501];
     long int find(int i,int n,int pick,int comp){
        if((pick==0&&comp==n)||(i==2*n)) return 1;
        long int &ans=dp[i][pick];
        long int del=n-pick-comp;
        if(ans!=-1) return ans;
        ans=1;
        if(pick>0&&del>0){
            long int ans1=((pick%MOD)*find(i+1,n,pick-1,comp)%MOD)%MOD;
            long int ans2=(del%MOD*find(i+1,n,pick,comp+1)%MOD)%MOD;
            ans=(ans%MOD*(ans1%MOD+ans2%MOD)%MOD)%MOD;
        }
        else if(pick>0&&del==0){
            long int ans1=((pick%MOD)*find(i+1,n,pick-1,comp)%MOD)%MOD;
            ans=(ans%MOD*ans1%MOD)%MOD;
        }
        else{
            long int ans2=(del%MOD*find(i+1,n,pick,comp+1)%MOD)%MOD;
            ans=(ans%MOD*ans2%MOD)%MOD;
        }
        ans=ans%MOD;
        return ans;
    }
    int countOrders(int n) {
        memset(dp,-1,sizeof(dp));
        return find(0,n,n,0);
    }
};