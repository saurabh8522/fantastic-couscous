class Solution {
public:
    int dp[41][41];
    int ma[41][41];
    int find(int l,int r,vector<int>&arr){
        if(l>=r){
            return dp[l][r]=0;
        }
        int & ans=dp[l][r];
        if(ans!=-1) return ans;
        ans=INT_MAX;
        // cout<<l<<" "<<r<<endl;
        for(int k=l;k<r;k++){
            ans=min(ans,find(l,k,arr)+find(k+1,r,arr)+ma[l][k]*ma[k+1][r]);
        }
        // cout<<l<<" * "<<r<<" * "<<ans<<endl;
        return ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr.size();j++){
                int m=0;
                for(int k=i;k<=j;k++){
                    m=max(m,arr[k]);
                }
                ma[i][j]=m;
            }
        }
        return find(0,arr.size()-1,arr);
    }
};