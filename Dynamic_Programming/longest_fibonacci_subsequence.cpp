class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        map<int,int>mp;
        mp.clear();
        for(int i=0;i<A.size();i++){
            mp[A[i]]=i;
        }
        int dp[1001][1001];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<A.size();i++){
            dp[i][0]=2;
        }
        int ans=0;
        for(int i=1;i<A.size();i++){
            dp[i][i]=1;
            for(int j=i-1;j>=0;j--){
                int cd=A[i]-A[j];
                if(mp.find(cd)!=mp.end()){
                    int idx=mp[cd];
                    if(idx<j){
                        dp[i][j]=max(dp[i][j],dp[j][idx]+1);
                        ans=max(ans,dp[i][j]);
                    }
                    else{
                        dp[i][j]=2;
                    }
                }
                else{
                    dp[i][j]=2;
                }
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        if(ans<3) return 0;
        return ans;
    }
};
