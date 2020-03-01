class Solution {
public:
    map< vector<int>,int >mp;
    int find(vector<int>&p, vector<vector<int>>& s, vector<int>&n){
        if(mp.find(n)!=mp.end()){
            // mp[done]=min(mp[done],price);
            return mp[n];
        }
        bool flag=true;
        for(int i=0;i<n.size();i++){
            if(n[i]!=0){
                flag=false;
                break;
            }
        }
        if(flag){
            return 0;
        }
         
        int ans=INT_MAX;
        int price=0;
        for(int i=0;i<n.size();i++){
            price+=n[i]*p[i];
        }
        ans=price;
        for(int i=0;i<s.size();i++){
            // cout<<"i="<<i<<endl;
            bool f=false;
            vector<int>temp=n;
            for(int j=0;j<s[0].size()-1;j++){
                temp[j]-=s[i][j];
                if(temp[j]<0){
                    // cout<<"t=  "<<temp[j]<<" "<<n[j]<<endl;
                    f=true;
                    break;
                }
            }
            if(f){
                continue;
            }
            // cout<<"i="<<i<<" psize= "<<p.size()<<" s="<<s[i][p.size()]<<endl;
            // return 0;
            ans=min(ans,s[i][p.size()]+find(p,s,temp));
        }
        
        mp.insert({n,ans});
        return ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int> >& special, vector<int>& needs) {
        vector< int>p(price.size(),0);
        mp[p]=0;
        // for(int i=0;i<price.size();i++){
        //     vector<int>v(price.size()+1,0);
        //     v[i]=1;
        //     v[price.size()]=price[i];
        //     special.push_back(v);
        // }
        // done.resize(price.size());
        // memset(done,0,sizeof(done));
        return find(price,special,needs);
    }
};