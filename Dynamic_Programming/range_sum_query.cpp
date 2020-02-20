class NumArray {
public:
    int ans;
    vector<int>sum;
    NumArray(vector<int>& nums) {
        
        ans=(-1)?(nums.size()==0):0;
        if(ans==0){
            sum.resize(nums.size());
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            sum[i]=sum[i-1]+nums[i];
        }
        }
        
    }
    
    int sumRange(int i, int j) {
        if(ans==-1){
            return 0;
        }
        if(i==0){
            return sum[j];
        }
        else{
            return sum[j]-sum[i-1];
        }
    }
};