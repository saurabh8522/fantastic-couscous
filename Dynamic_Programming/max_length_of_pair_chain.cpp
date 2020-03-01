class Solution {
public:
    static bool mycomp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
       return (a[0]<b[0]); 
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),mycomp);
        int n=pairs.size();
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                int b=pairs[j][1];
                int c=pairs[i][0];
                if(b<c){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};