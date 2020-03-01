class Solution {
public:
    double  dp[26][26][101];
    
    double find(int N,int K,int r,int c){
        if(r<0||r>=N||c<0||c>=N) return 0.0;
        
        if(K==0){
            return 1.0;
        }
        
        double &ans = dp[r][c][K];
        if(ans>=0){
            return ans;
        }
        double ans1=find(N,K-1,r-1,c-2);
        double ans2=find(N,K-1,r-2,c-1);
        double ans3=find(N,K-1,r-2,c+1);
        double ans4=find(N,K-1,r-1,c+2);
        double ans5=find(N,K-1,r+1,c+2);
        double ans6=find(N,K-1,r+2,c+1);
        double ans7=find(N,K-1,r+2,c-1);
        double ans8=find(N,K-1,r+1,c-2);
        ans=ans1+ans2+ans3+ans4+ans5+ans6+ans7+ans8;
        // cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<" "<<ans5<<" "<<ans6<<" "<<ans7<<" "<<ans8<<endl;
        ans/=8.0;
        // cout<<ans<<endl;
        return ans;
    }
    double knightProbability(int N, int K, int r, int c) {
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<101;k++){
                    dp[i][j][k]=(-1.0);
                }
            }
        }
        return find(N,K,r,c);
    }
};