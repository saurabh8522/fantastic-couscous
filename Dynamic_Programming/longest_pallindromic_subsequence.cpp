class Solution {
public:
    // int dp[1001][1001];
    int find(int l,int r, string &s,vector< vector<int> >&dp){
        if(l==r) return 1;
        if(l>r) return 0;
        // int &ans=dp[l][r];
        if(dp[l][r]!=-1) return dp[l][r];
        // dp[l][r]=0;
        // cout<<l<<" "<<r<<endl;
        if(s[l]==s[r]){
            // cout<<l<<" * "<<r<<endl;
            dp[l][r]=2+find(l+1,r-1,s,dp);
        }
        else{
            dp[l][r]=max(find(l+1,r,s,dp),find(l,r-1,s,dp));
        }
        // cout<<l<<" * "<<r<<" * "<<ans<<endl;
        return dp[l][r];
    }
    int longestPalindromeSubseq(string s) {
        // int n=s.size();
        vector< vector<int> >dp(s.size(),vector<int>(s.size(),-1));
        // memset(dp,-1,sizeof(dp));
        return find(0,s.size()-1,s,dp);
    }
};