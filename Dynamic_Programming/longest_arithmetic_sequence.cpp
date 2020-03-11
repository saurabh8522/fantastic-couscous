class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if(A.size()<2) return A.size();
        map< pair<int,int>,int>mp;
        // for(int i=0;i<=A.size();i++){
        //     for(int j=-20000;j<=20000;j++){
        //         mp[{i,j}]=1;
        //     }
        // }
        // memset(dp,1,sizeof(dp));
        int ans=1;
        for(int i=1;i<A.size();i++){
            for(int j=i-1;j>=0;j--){
                int cd=A[i]-A[j];
                if(mp.find({j,cd})==mp.end()){
                    mp[{j,cd}]=1;
                }
                mp[{i,cd}]=max(mp[{i,cd}],mp[{j,cd}]+1);
                ans=max(ans,mp[{i,cd}]);
            }
        }
        return ans;
    }
};