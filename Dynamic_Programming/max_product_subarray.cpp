class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int neg=0;
        long int p=1,p1=1,p2=1;
        bool flag=false;
        int first=-1,last=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0){
                neg++;
                if(!flag){
                    first=i;
                }
                flag=true;
                last=i;
            }
            p*=nums[i];
        }
        if(neg%2==0){
            return p;
        }
        for(int i=0;i<last;i++){
            p2*=nums[i];
        }
        for(int i=first+1;i<nums.size();i++){
            p1*=nums[i];
        }
        return max(p1,p2);
    }
};