class Solution {
public:
    static bool compare(const string &s,const string &t){
        return s.size()>t.size();
    }
    bool one(string &s,string &t){
        if(s.size()-t.size()!=1) return false;
        int diff=0;
        int i=0,j=0;
        while(i<s.size()&&j<t.size()){
            if(s[i]!=t[j]){
                diff++;
                i++;
                continue;
            }
            i++;
            j++;
        }
        if(diff>1) return false;
        if(i==s.size()&&j==t.size()&&diff==1) return true;
        if(diff==1&&(i!=s.size())) return false;
        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        // sort(words.begin(),words.end());
        // reverse(words.begin(),words.end());
        if(words.size()<2) return words.size();
        int dp[words.size()];
        for(int i=0;i<words.size();i++){
            dp[i]=1;
        }
        int ans=1;
        for(int i=1;i<words.size();i++){
            for(int j=i-1;j>=0;j--){
                // string s=words[i],t=words[j];
                // cout<<s<<" "<<t<<" "<<one(s,t)<<endl;
                if(one(words[j],words[i])){
                    dp[i]=max(dp[i],dp[j]+1);
                    // cout<<i<<" "<<j<<" "<<dp[i]<<" "<<dp[j]<<endl;
                    ans=max(ans,dp[i]);
                }
            }
            // cout<<endl;
        }
        return ans;
    }
};