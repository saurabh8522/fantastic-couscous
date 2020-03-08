class Solution {
public:
    int dp[1001][1001][2];
    int find(vector<int>& A, vector<int>& B,int i,int j,int flag){
        if(i<0||j<0){
            return 0;
        }
        int &ans=dp[i][j][flag];
        if(ans!=-1){
            return ans;
        }
        ans=0;
        if(!flag){
            ans=max(ans,max(find(A,B,i-1,j,0),find(A,B,i,j-1,0)));
            if(A[i]==B[j]){
                ans=max(ans,1+find(A,B,i-1,j-1,1));   
            }
        }
        else{
            if(A[i]==B[j]){
                ans=1+find(A,B,i-1,j-1,1);
                // ans=max(ans,max(find(A,B,i-1,j,0),find(A,B,i,j-1,0)));
            }
            
        }
        return ans;
    }
    int findLength(vector<int>& A, vector<int>& B) {
        int m=A.size(),n=B.size();
        memset(dp,-1,sizeof(dp));
        // int gans=0;
        return max(find(A,B,m-1,n-1,0),find(A,B,m-1,n-1,1));
        // return gans;
    }
};