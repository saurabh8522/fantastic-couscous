class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans=0;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<m;i++){
            vector<int>rowsum(n,0);
            for(int j=i;j<m;j++){
                map<int,int>mp;
                // mp[0]=1;
                int sum=0;
                for(int k=0;k<n;k++){
                    rowsum[k]+=matrix[k][j];
                    sum+=rowsum[k];
                    if(sum==target) ans++;
                    // else{
                        if(mp.find(sum-target)!=mp.end()){
                            ans+=mp[sum-target];
                        }
                    // }
                    mp[sum]++;
                    // cout<<i<<" "<<j<<" "<<ans<<endl;
                }
            }
        }
        return ans;
    }
};