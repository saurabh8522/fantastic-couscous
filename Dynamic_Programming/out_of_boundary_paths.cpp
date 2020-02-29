#define MOD 1000000007
class Solution {
public:
    long int dp[51][51][51];
    int find(int m,int n,int N,int curri,int currj){
        if(curri<0||currj<0||curri>m-1||currj>n-1){
            return 1;
        }
        if(N<=0)
            return 0;
        if(dp[curri][currj][N]!=-1){
            return dp[curri][currj][N];
        }
        long int ans1=find(m,n,N-1,curri-1,currj);
        long int ans2=find(m,n,N-1,curri+1,currj);
        long int ans3=find(m,n,N-1,curri,currj-1);
        long int ans4=find(m,n,N-1,curri,currj+1);
        dp[curri][currj][N]=(ans1+ans2+ans3+ans4)%MOD;
        return dp[curri][currj][N];
    }
    int findPaths(int m, int n, int N, int i, int j) {
        for(int i=0;i<51;i++){
            for(int j=0;j<51;j++){
                for(int k=0;k<51;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        return find(m,n,N,i,j);
    }
};