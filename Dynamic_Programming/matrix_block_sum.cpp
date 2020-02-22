class Solution {
public:
    int Sum(int i,int j,vector< vector<int> >&sum,int n,int m){
        if(i<0||j<0) return 0;
        if(i>=n) i=n-1;
        if(j>=m) j=m-1;
        return sum[i][j];
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        vector< vector<int> >sum(n,vector<int>(m,0));
        sum[0][0]=mat[0][0];
        for(int i=1;i<m;i++){
            sum[0][i]=sum[0][i-1]+mat[0][i];
        }
        for(int i=1;i<n;i++){
            sum[i][0]=sum[i-1][0]+mat[i][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                sum[i][j]=mat[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
                // cout<<sum[i][j]<<" ";
            }
            // cout<<endl;
        }
        vector<vector<int>>ans;
        ans.resize(n);
        for(int i=0;i<n;i++){
            ans[i].resize(m);
            for(int j=0;j<m;j++){
                ans[i][j]=Sum(i+k,j+k,sum,n,m)-Sum(i-k-1,j+k,sum,n,m)-Sum(i+k,j-k-1,sum,n,m)+Sum(i-k-1,j-k-1,sum,n,m);
            }
        }
        return ans;
        
    }
    
};