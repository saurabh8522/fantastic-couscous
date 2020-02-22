class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>mp;
        for(int i=0;i<wordDict.size();i++){
            mp[wordDict[i]]=true;
        }
        vector<int>st;
        st.push_back(-1);
        for(int i=0;i<s.size();i++){
            for(int j=st.size()-1;j>=0;j--){
                string curr=s.substr(st[j]+1,i-st[j]);
                // cout<<curr<<" "<<i<<" "<<j<<endl;
                if(mp[curr]){
                    st.push_back(i);
                    break;
                    // cout<<i<<endl;
                }
            }
        }
        return (st[st.size()-1]==s.size()-1);
    }
};