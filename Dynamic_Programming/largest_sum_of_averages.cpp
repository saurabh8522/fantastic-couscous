class Solution {
public:
    double dp[101][101];
    double find(int i,int j,vector<int>&A){
        if(i==A.size()){
            return 0;
        }
        // if(j==-1){
        //     return 0.0;
        // }
        double &ans=dp[i][j];
        // cout<<ans<<endl;
        if(ans>=0) return ans;
        ans=0.0;
        // cout<<i<<" "<<j<<endl;
        int temp=0,tsum=0;    
        int sum=0,n=0;
        if(j>1){
            for(int k=i;k<A.size();++k){
                sum+=A[k];
                n++;
                ans=max(ans,(sum/(double)n)+find(k+1,j-1,A));
            }
        }
        if(j==1){
            for(int k=i;k<A.size();++k){
                tsum+=A[k];
                temp++;
            }
            ans=max(ans,tsum/(double)(temp));
        }
        // cout<<i<<" "<<j<<" "<<sum<<" "<<n<<" "<<ans<<endl;
        return ans;
    }
    double largestSumOfAverages(vector<int>& A, int K) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j]=-1.0;
            }
        }
        // for(int i=0;i<A.size();i++){
        //     dp[i][0]=0;
        // }
        // dp[0][0]=0;
        int n=A.size();
        find(0,K,A);
        double ans=-1.0;
        for(int i=1;i<=K;i++){
            ans=max(ans,dp[0][i]);
        }
        return ans;
    }
};