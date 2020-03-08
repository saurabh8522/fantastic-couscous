class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int arr[N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                arr[i][j]=1;
            }
        }
        for(int i=0;i<mines.size();i++){
            arr[mines[i][0]][mines[i][1]]=0;
        }
        int dp[N][N];
        int ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                // cout<<arr[i][j]<<endl;
                if(arr[i][j]==1){
                    // cout<<i<<" "<<j<<endl;
                    int l=1;
                    while(j-l>=0&&j+l<N&&i-l>=0&&i+l<N){
                        if(!arr[i][j-l]||!arr[i][j+l]||!arr[i-l][j]||!arr[i+l][j]){
                            break;
                        }
                        l++;
                        // l++;
                    }
                    dp[i][j]=l;
                    // cout<<dp[i][j]<<endl;
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};