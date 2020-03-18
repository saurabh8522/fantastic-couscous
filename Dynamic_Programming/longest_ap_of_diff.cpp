class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n=arr.size();
        map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            int a=arr[i]-diff;
            if(mp.find(a)==mp.end()){
                mp[arr[i]]=1;
                ans=max(ans,1);
            }
            else{
                mp[arr[i]]=max(mp[arr[i]],mp[a]+1);
                ans=max(ans,mp[arr[i]]);
            }
        }
        return ans;
    }
};