class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(),clips.end());
        int ans=INT_MAX;
        int dp[clips.size()];
        for(int i=0;i<clips.size();i++){
            dp[i]=INT_MAX;
        }
        for(int i=0;i<clips.size();i++){
            if(clips[i][0]!=0){
                for(int j=i-1;j>=0;j--){
                    if(clips[j][1]>=clips[i][0]&&dp[j]!=INT_MAX){
                        dp[i]=min(dp[i],dp[j]+1);
                    }
                }
            }
            else{
                dp[i]=1;
            }
        }
        for(int i=0;i<clips.size();i++){
            if(clips[i][1]>=T){
                ans=min(ans,dp[i]);
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};