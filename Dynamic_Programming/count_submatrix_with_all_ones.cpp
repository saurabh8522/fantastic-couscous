class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector< vector<int> >dp;
        dp.resize(matrix.size());
        int count=0;
        for(int i=0;i<matrix.size();i++){
            dp[i].resize(matrix[0].size());
        }
        for(int i=0;i<matrix[0].size();i++){
            dp[0][i]=matrix[0][i];
            count+=dp[0][i];
        }
        // cout<<count<<endl;
        for(int i=1;i<matrix.size();i++){
            dp[i][0]=matrix[i][0];
            count+=dp[i][0];
        }
        // cout<<count<<endl;
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(!matrix[i][j]){dp[i][j]=0; continue;}
                dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                count+=dp[i][j];
            }
        }
        return count;
    }
};