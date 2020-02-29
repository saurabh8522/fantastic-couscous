/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
Code author: Saurabh Singhal
Code copy karne vaale tera muh kaala
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define ppb pop_back

using namespace std;
typedef long long int ll;
typedef vector<int> vi_t;
typedef vector<ll> vll_t;
int t=1;
vll_t a,b;
map<vector<int>,int>mp;
int find(vector<int>&p, vector<vector<int>>& s, vector<int>&n,vector<int>done,int price){
        for(int i=0;i<done.size();i++){
            cout<<done[i]<<" ";
        }
        cout<<"price="<<price<<endl;
        cout<<endl;
        bool flag=true;
        for(int i=0;i<done.size();i++){
            if(done[i]!=n[i]){
                flag=false;
                break;
            }
        }
        if(flag){
            return price;
        }
         if(mp.find(done)!=mp.end()){
            mp[done]=min(mp[done],price);
            return mp[done];
        }
        int ans=INT_MAX;
        for(int i=0;i<s.size();i++){
            cout<<"i="<<i<<endl;
            bool f=false;
            vector<int>temp=done;
            for(int j=0;j<s[0].size()-1;j++){
                temp[j]+=s[i][j];
                if(temp[j]>n[j]){
                    cout<<"t=  "<<temp[j]<<" "<<n[j]<<endl;
                    f=true;
                    break;
                }
            }
            if(f){
                continue;
            }
            cout<<"i="<<i<<" psize= "<<p.size()<<" s="<<s[i][p.size()]<<endl;
            ans=min(ans,find(p,s,n,temp,price+s[i][p.size()]));
        }
        for(int i=0;i<done.size();i++){
            if(done[i]<n[i]){
                vector<int>temp=done;
                temp[i]++;
                ans=min(ans,find(p,s,n,temp,price+p[i]));
            }
        }
        mp[done]=ans;
        return ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int> >& special, vector<int>& needs) {
        vector<int>done(price.size(),0);
        // done.resize(price.size());
        // memset(done,0,sizeof(done));
        return find(price,special,needs,done,0);
    }
int  main(){
    vector<int>price={2,5};
    vector< vector<int > >special = {{3,0,5},{1,2,10}};
    vector<int>need={3,2};
    // cout<<special.size()<<endl;
    cout<<shoppingOffers(price,special,need)<<endl;
}
    