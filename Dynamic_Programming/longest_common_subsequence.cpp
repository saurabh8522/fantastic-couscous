class Solution {
public:
    int dp[1001][1001];
    int find(int i,int j,string &s1,string &s2){
        if(i>=s1.size()||j>=s2.size()) return 0;
        int &ans=dp[i][j];
        if(ans!=-1) return ans;
        ans=0;
        if(s1[i]==s2[j]){
            ans=1+find(i+1,j+1,s1,s2);
        }
        ans=max(ans,max(find(i+1,j,s1,s2),find(i,j+1,s1,s2)));
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,text1,text2);
    }
};