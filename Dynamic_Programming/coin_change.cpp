class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        map<long int,int>mp;
        for(int i=0;i<coins.size();i++){
            mp[coins[i]]=1;
        }
        // cout<<endl;
        
            int x= ans(mp,coins,amount);
        if(x==0){
            return -1;
        }
        return x;
    }
    int ans(map<long int,int>&mp,vector<int>&coins,int amount){
        if(mp.find(amount)!=mp.end()){
            return mp[amount];
        }
        
        int an=INT_MAX;
        // cout<<amount<<endl;
        for(int i=0;i<coins.size();i++){
            if(amount>=coins[i]){
                int x= ans(mp,coins,amount-coins[i]);
                if(x==0){
                    mp[amount]=0;
                    // cout<<amount<<" ** "<<mp[amount]<<endl;
                    continue;
                }
                an=min(an,x+1);
                // cout<<amount<<" -> "<<" "<<amount-coins[i]<<" "<<mp[amount-coins[i]]<<" "<<an<<endl;
                // mp[amount]=an;
            }
        }
        if(an==INT_MAX){
            an=0;
        }
        mp[amount]=an;
        // cout<<amount<<" ** "<<an<<endl;
        if(an==INT_MAX) return 0;
        return an;
    }
};