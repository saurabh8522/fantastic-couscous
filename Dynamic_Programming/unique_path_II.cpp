class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        long int a[obstacleGrid.size()][obstacleGrid[0].size()];
        memset(a,0,sizeof(a));
        long int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        if(n==1&&m==1){
            return 1-obstacleGrid[0][0];
        }
        a[0][0]=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(obstacleGrid[i][j]==1){
        //             a[i][j]=0;
        //         }
        //     }
        // }
        for(int i=1;i<m;i++){
            if(obstacleGrid[0][i]!=1){
                a[0][i]=1;
            }
            else{
                break;
            }
        }
        for(int i=1;i<n;i++){
            if(obstacleGrid[i][0]!=1){
                a[i][0]=1;
            }
            else{
                break;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j]!=1){
                    a[i][j]=a[i-1][j]+a[i][j-1];
                }
            }
        }
        return a[n-1][m-1];
    }
};