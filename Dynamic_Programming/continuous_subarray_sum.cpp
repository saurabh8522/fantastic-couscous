class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        mp.insert({0,-1});
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(k!=0) sum=sum%k;
            if(mp.find(sum)!=mp.end()){
                if(i-mp[sum]>1)
                    return true;
            }
            else{
                mp.insert({sum,i});
            }
            
        }
        return false;
    }
};