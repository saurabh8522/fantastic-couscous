class Solution {
public:
    bool find(vector<int>&nums,int k,int pos,int req,vector<int>&sum){
        if(pos<0){
            // for(int i=0;i<k;i++){
            //     if(sum[i]!=req){
            //         return false;
            //     }
            // }
            return true;
        }
        // int ele=nums[pos];
        // bool ans;
        for(int i=0;i<k;i++){
            if(sum[i]+nums[pos]<=req){
                // dp[i].push_back(nums[pos]);
                sum[i]+=nums[pos];
                if(find(nums,k,pos-1,req,sum)) return true;
                // if(ans) return true;
                // dp[i].pop_back();
                sum[i]-=nums[pos];
            }
            if(sum[i]==0) return false;
            // ans=ans|(find(nums,k,pos+1,req,sum));
            // if(ans) return true;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        if(s%k!=0){
            return false;
        }
        int reqsum=s/k;
        if(nums[nums.size()-1]>reqsum) return false;
        int pos=nums.size()-1;
        // while(k>0&&nums[pos]==reqsum){
        //     k--;
        //     pos--;
        // }
        vector<int>sum(k,0);
        // vector< vector<int> >dp;
        // dp.resize(k);
        // memset(sum,0,sizeof(sum));
        return find(nums,k,pos,reqsum,sum);
    }
};