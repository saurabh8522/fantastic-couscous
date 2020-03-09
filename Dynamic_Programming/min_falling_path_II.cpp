class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A.size();
        // int ans=INT_MAX;
        int dp[n][n];
        if(n==1){
            return A[0][0];
        }
        long int mi=INT_MAX,sec_mi=INT_MAX,mi_idx=-1;
        for(int i=0;i<n;i++){
            if(A[0][i]<mi){
                sec_mi=mi;
                mi=A[0][i];
                mi_idx=i;
            }
            else if(A[0][i]<sec_mi){
                sec_mi=A[0][i];
            }
        }
        // cout<<mi<<" "<<sec_mi<<" "<<mi_idx<<endl;
        // int ans=INT_MAX;
        for(int i=1;i<n;i++){
            long int curr_mi=INT_MAX,curr_sec_mi=INT_MAX,curr_mi_idx=-1;
            for(int j=0;j<n;j++){
                int val=A[i][j];
                if(j==mi_idx){
                    val+=sec_mi;
                }
                else{
                    val+=mi;
                }
                if(val<curr_mi){
                    curr_sec_mi=curr_mi;
                    curr_mi=val;
                    curr_mi_idx=j;
                }
                else if(val<curr_sec_mi){
                    curr_sec_mi=val;
                }
            }
            mi=curr_mi,sec_mi=curr_sec_mi,mi_idx=curr_mi_idx;
            // cout<<endl;
            
        }
        return mi;
    }
};