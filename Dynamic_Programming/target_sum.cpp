class Solution {
public:
    int find(vector<int>&nums,int S,int sum,int pos){
        if(pos==nums.size()&&sum!=S){
            return 0;
        }
        if(pos==nums.size()&&sum==S){
            return 1;
        }
        int ans1=find(nums,S,sum+nums[pos],pos+1);
        int ans2=find(nums,S,sum-nums[pos],pos+1);
        // cout<<ans1<<" "<<ans2<<" "<<sum<<" "<<pos<<endl;
        return ans1+ans2;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        return find(nums,S,0,0);
    }
};