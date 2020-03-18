class Solution {
public:
    int dp[51][51];
    int find(vector<int>&A,int l, int r){
        if(r-l<2) return 0;
        // if(r-l==2) return A[l]*A[l+1]*A[l+2];
        int &ans=dp[l][r];
        if(ans!=-1) return ans;
        ans=INT_MAX;
        for(int i=l+1;i<r;i++){
            ans=min(ans,A[l]*A[r]*A[i]+find(A,l,i)+find(A,i,r));
        }
        return ans;
    }
    int minScoreTriangulation(vector<int>& A) {
        memset(dp,-1,sizeof(dp));
        return find(A,0,A.size()-1);
    }
};