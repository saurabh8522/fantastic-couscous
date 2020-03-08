class Solution {
public:
    int dp[501][501][2];
    int find(int l,int r,int chance,vector<int>& piles){
        if(l>r) return 0;
        if(l==r&&chance==0) return piles[l];
        if(l==r&&chance==1) return -piles[l];
        int &ans=dp[l][r][chance];
        if(ans!=-1) return ans;
        if(chance==0){
            ans=0;
            ans=max(piles[l]+find(l+1,r,1-chance,piles),piles[r]+find(l,r-1,1-chance,piles));
        }
        else{
            ans=INT_MAX;
            ans=min(-piles[l]+find(l+1,r,1-chance,piles),-piles[r]+find(l,r-1,1-chance,piles));
        }
        return ans;
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return find(0,piles.size()-1,0,piles)>0;
    }
};