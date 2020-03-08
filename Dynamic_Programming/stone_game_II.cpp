class Solution {
public:
    int dp[101][101][2];
    int sum[101];
    int find(int chance,int pos,int m,int n,vector<int>&piles){
        if(pos>=n) return 0;
        int &ans=dp[pos][m][chance];
        if(ans!=-1) return ans;
        if(chance==0) ans=-INT_MAX;
        else ans=INT_MAX;
        for(int i=0;i<2*m;i++){
            if(pos+i>=n) break;
            int s;
            if(pos==0) s=sum[i];
            else s=sum[pos+i]-sum[pos-1];
            int x=i+1;
            // cout<<pos<<" "<<i<<" "<<s<<endl;
            if(chance==0){
                int ans1=find(1-chance,pos+i+1,max(m,x),n,piles);
                
                ans=max(ans,s+ans1);
                // cout<<chance<<" ** "<<ans1<<" "<<ans<<endl;
            }
            else{
                int ans1=find(1-chance,pos+i+1,max(m,x),n,piles);
                
                ans=min(ans,-s+ans1);
                cout<<chance<<" ** "<<ans1<<" "<<ans<<endl;
            }
            
            // cout<<ans1<<" ** "<<ans<<" "<<pos<<" "<<m<<" "<<chance<<endl;
        }
        return ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        memset(sum,0,sizeof(sum));
        memset(dp,-1,sizeof(dp));
        sum[0]=piles[0];
        for(int i=1;i<piles.size();i++){
            sum[i]=sum[i-1]+piles[i];
        }
        int ans=find(0,0,1,n,piles);
        return (sum[n-1]+ans)/2;
    }
};