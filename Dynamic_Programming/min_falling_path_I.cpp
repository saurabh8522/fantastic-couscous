class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A.size();
        int ans=INT_MAX;
        if(n==1){
            return A[0][0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    A[i][j]+=min(A[i-1][0],A[i-1][1]);
                }
                else if(j==n-1){
                    A[i][j]+=min(A[i-1][j],A[i-1][j-1]);
                }
                else{
                    A[i][j]+=min(A[i-1][j-1],min(A[i-1][j],A[i-1][j+1]));
                }
                if(i==n-1){
                    ans=min(ans,A[i][j]);
                }
            }
            
        }
        return ans;
    }
};