class Solution {
public:
    long int dp[200][200][200];
    long int find(int n, vector< pair<int,int > >flight[], int src, int dst, int K){
        if(src==dst) return 0;
        if(K<0) return INT_MAX;
        if(flight[src].size()==0) return INT_MAX;
        long int &ans=dp[src][dst][K];
        if(ans!=INT_MAX){
            return ans;
        }
        for(int i=0;i<flight[src].size();i++){
            // cout<<src<<" "<<dst<<" "<<i<<" "<<flight[src][i].first<<endl;
            ans=min(ans,flight[src][i].second+find(n,flight,flight[src][i].first,dst,K-1));
        }
        // cout<<src<<" "<<dst<<" "<<dp[src][dst][K]<<endl;
        return ans;
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        for(int i=0;i<200;i++){
            for(int j=0;j<200;j++){
                for(int k=0;k<200;k++){
                    dp[i][j][k]=INT_MAX;
                }
            }
        }
        vector< pair<int,int > >flight[101];
        for(int i=0;i<flights.size();i++){
            flight[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        find(n,flight,src,dst,K);
        long int ans=INT_MAX;
        for(int i=0;i<=K;i++){
            ans=min(ans,dp[src][dst][i]);
        }
        if(ans==INT_MAX) return -1;
                   return ans;
    }
};