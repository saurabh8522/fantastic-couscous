class Solution {
public:
    int dp[601][101][101];
    map< int, pair<int,int> >mp;
   int find(vector<string>&str,int pos,int m,int n){
        int n0=mp[pos].first,n1=mp[pos].second;
         if(pos==str.size()){
            return 0;
        }
        if(dp[pos][m][n]!=-1){
            return dp[pos][m][n];
        }
       int ans1,ans2;
       if(m>=n0&&n>=n1){
           ans1=find(str,pos+1,m,n);
           ans2=find(str,pos+1,max(m-n0,0),max(n-n1,0))+1;
       }
       else{
           ans1=find(str,pos+1,m,n);
           ans2=0;
       }
       //  int ans1=find(str,pos+1,m,n);
       // int ans2=find(str,pos+1,max(m-n0,0),max(n-n1,0))+1;
       // cout<<ans1<<" "<<ans2<<" "<<pos<<" "<<m<<" "<<n<<endl;
       dp[pos][m][n]=max(ans1,ans2);
        return dp[pos][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(int i=0;i<601;i++){
            for(int j=0;j<101;j++){
                for(int k=0;k<101;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        for(int i=0;i<strs.size();i++){
            int n1=0,n0=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='1'){
                    n1++;
                }
                else{
                    n0++;
                }
            }
            mp[i]={n0,n1};
        }
        return find(strs,0,m,n);
    }
};