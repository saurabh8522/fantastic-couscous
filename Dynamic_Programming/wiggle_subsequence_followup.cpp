class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return n;
        }
        int currsign=0,ans=1;
        for(int i=1;i<n;i++){
            int sign=nums[i]-nums[i-1];
            if(sign!=currsign&&sign!=0){
                ans++;
                currsign=sign;
            }
        }
        return ans;
    }
};