int dp[5000000][2];
class Solution {
public:
    // vector< vector<int> >dp;
    int m;
    int check(int sum,int chance,int n){
        if(sum<=0){
            return 0;
        }
        if(dp[n][chance]!=-1){
            return dp[n][chance];
        }
        // cout<<dp[sum][chance]<<endl;
        dp[n][chance]=1;
        for(int i=1;i<=m;++i){
            if((n&(1<<i))>0){
                int temp=n-(1<<i);
                dp[n][chance]=(dp[n][chance])&(check(sum-i,1-chance,temp));
            }
        }
        dp[n][chance]=!dp[n][chance];
        // for(int i=1;i<=m;++i){
        //     if((n&(1<<i))>0){
        //         cout<<i<<",";
        //     }
        // }
        // // cout<<" "<<sum<<" "<<chance<<" "<<dp[n][chance]<<endl;
        return dp[n][chance];
    }
    bool canIWin(int ma, int Total) {
        int sum=Total;
        m=ma;
        if(sum==0){
            return true;
        }
        if((ma*(ma+1))/2<Total){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        // for(int i=0;i<SIZE;i++){
        //     dp[i][1]=-1;
        //     dp[i][0]=-1;
        // }
        long int  n=(1<<(ma+1))-2;
        return check(sum,0,n);
    }
};