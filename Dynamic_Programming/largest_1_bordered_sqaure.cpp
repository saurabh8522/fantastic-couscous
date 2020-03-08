class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(n==1&&m==1) return grid[0][0];
        int left[n][m];
        int top[n][m];
        int ans=0;
        left[0][0]=top[0][0]=ans=grid[0][0];
        for(int i=1;i<n;i++){
            if(grid[i][0]==0){
                left[i][0]=0;
                top[i][0]=0;
            }
            else{
                left[i][0]=1;
                ans=1;
                top[i][0]=top[i-1][0]+1;
            }
        }
        for(int i=1;i<m;i++){
            if(grid[0][i]==0){
                left[0][i]=0;
                top[0][i]=0;
            }
            else{
                left[0][i]=left[0][i-1]+1;
                ans=1;
                top[0][i]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==0){
                    top[i][j]=left[i][j]=0;
                }
                else{
                    ans=1;
                    left[i][j]=left[i][j-1]+1;
                    top[i][j]=top[i-1][j]+1;
                }
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                // cout<<top[i][j]<<" "<<left[i][j]<<endl;
                if(min(top[i][j],left[i][j])==1){
                    ans=max(ans,1);
                    continue;
                }
                int a=min(top[i][j],left[i][j]);
                for(int r=1;r<a;r++){
                    if(min(top[i][j-r],left[i-r][j])>=r+1){
                        ans=max(ans,r+1);
                    }
                }
            }
        }
        return ans*ans;
    }
};