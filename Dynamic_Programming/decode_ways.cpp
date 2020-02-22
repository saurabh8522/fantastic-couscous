class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        if(s.size()<=1){
            return s.size();
        }
        bool flag=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'&&s[i-1]=='0'){
                return 0;
            }
        }
        int ans[s.size()+1];
        memset(ans,0,sizeof(ans));
        ans[0]=1;ans[1]=1;
        
        for(int i=2;i<=s.size();i++){
            if(s[i-1]=='0'){
                if(s[i-2]-'0'<=2){
                    ans[i]=ans[i-2];
                }
                else{
                    return 0;
                }
            }
            else{
                if(s[i-2]-'0'>2||s[i-2]-'0'==0){
                    ans[i]=ans[i-1];
                }
                else{
                    if(s[i-1]-'0'>6&&s[i-2]>='2'){
                        ans[i]=ans[i-1];
                    }
                    else{
                        ans[i]=ans[i-1]+ans[i-2];
                    }
                }
            }
        }
        return ans[s.size()];
    }
};