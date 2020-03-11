class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2){
            return s;
        }
        string res="";
        int ans=1,start=0,end=0;
        int n=s.size();
        for(int i=1;i<n-1;i++){
            // cout<<i<<endl;
            int l=i-1,r=i+1,len=1;
            while(s[l]==s[r]&&l>=0&&r<=n-1){
                len+=2;
                l--;
                r++;
                if(l<0||r>=n) break;
            }
            if(len>ans){
                ans=len;
                start = l+1;
                end=r-1;
            }
        }
        // cout<<start<<" "<<end<<endl;

        for(int i=0;i<n-1;i++){
            int l=i,r=i+1,len=1;
            while(s[l]==s[r]&&l>=0&&r<=n-1){
                len+=2;
                l--;
                r++;
                if(l<0||r>=n) break;
            }
            if(len>ans){
                ans=len;
                start = l+1;
                end=r-1;
            }
        }
        // cout<<start<<" "<<end<<endl;
        // string res="";
        for(int i=start;i<=end;i++){
            res+=s[i];
        }
        return res;
    }
};