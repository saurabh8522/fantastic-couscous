class Solution {  
public:
    int findSubstringInWraproundString(string p) {
        int res=0,len=0;
        vector<int>v(26,0);
        for(int i=0;i<p.size();i++){
            int a= p[i]-'a';
            if(i>0&&(a+26-1)%26!=p[i-1]-'a'){
                len=1;
            }
            else{
                len++;
            }
            if(len>v[a]){
                res+=len-v[a];
                v[a]=len;
            }
        }
        return res;
    }
};