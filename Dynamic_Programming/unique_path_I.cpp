class Solution {
public:
    int uniquePaths(int m, int n) {
        int a[n][m];
        a[0][0]=1;
        for(int i=1;i<m;i++){
            a[0][i]=1;
        }
        for(int i=1;i<n;i++){
            a[i][0]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                a[i][j]=a[i-1][j]+a[i][j-1];
            }
        }
        return a[n-1][m-1];
    }
};