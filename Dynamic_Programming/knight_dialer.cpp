#define MOD 1000000007
class Solution {
public:
    int dp[10][5001];
    vector<int>v[10];
    int find(int last,int rem){
        if(rem==0) return 1;
        // if(last==5) return 1;
        int &ans=dp[last][rem];
        if(ans!=-1) return ans;
        ans=0;
        for(int i=0;i<v[last].size();i++){
            ans=ans+find(v[last][i],rem-1);
            // cout<<ans<<" "<<last<<" "<<v[last][i]<<" "<<rem<<endl;
            ans=ans%MOD;
        }
        return ans;
    }
    int knightDialer(int N) {
        memset(dp,-1,sizeof(dp));
        // v.clear();
        v[0].push_back(4);v[0].push_back(6);
        v[1].push_back(8);v[1].push_back(6);
        v[2].push_back(7);v[2].push_back(9);
        v[3].push_back(4);v[3].push_back(8);
        v[4].push_back(9);v[4].push_back(3);v[4].push_back(0);
        v[6].push_back(1);v[6].push_back(7);v[4].push_back(0);
        v[7].push_back(2);v[7].push_back(6);
        v[8].push_back(1);v[8].push_back(3);
        v[9].push_back(2);v[9].push_back(4);
        int ans=0;
        for(int i=0;i<10;i++){
            ans=ans+find(i,N-1);
            ans=ans%MOD;
        }
        return ans;
    }
};