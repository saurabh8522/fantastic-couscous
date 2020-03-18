class Solution {
public:
    int dp[1001][1001];
    int find(int i,int j,int n,int m,string &t1,string &t2){
        if(i>=t1.size()||j>=t2.size()){
            return 0;
        }
        int &ans=dp[i][j];
        if(ans!=-1) return ans;
        ans=0;
        if(t1[i]==t2[j]){
            ans=max(ans,t1[i]+find(i+1,j+1,n,m,t1,t2));
        }
        int ans1=find(i+1,j,n,m,t1,t2);
        int ans2=find(i,j+1,n,m,t1,t2);                                                                       ans=max(ans,max(ans1,ans2));
        return ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        int n=s1.size(),m=s2.size();
        for(int i=0;i<s1.size();i++){
            sum+=s1[i];
        }
        for(int i=0;i<s2.size();i++){
            sum+=s2[i];
        }
        return sum-2*find(0,0,s1.size(),s2.size(),s1,s2);
    }
};