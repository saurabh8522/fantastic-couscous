class Solution {
public:
    int dp[31][3001];
    int find(vector<int>&stones,int i,int sum){
        if(sum<0) return 0;
        if(sum==0) return 1;
        if(i==-1) return 0;
        int &ans=dp[i][sum];
        if(ans!=-1) return ans;
        ans=0;
        ans=find(stones,i-1,sum)|find(stones,i-1,sum-stones[i]);
        return ans;
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(int i=0;i<stones.size();i++){
            sum+=stones[i];
        }
        for(int i=sum/2;i>=0;i--){
            if(find(stones,stones.size()-1,i)){
                return sum-2*i;
            }
        }
        return 0;
    }
};