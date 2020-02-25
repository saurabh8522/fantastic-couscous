class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>ans(num+1);
        ans[0]=0;
        if(num==0){
            return ans;
        }
        ans[1]=1;
        int curr=1;
        for(int i=2;i<=num;i++){
            if(curr*2==i){
                ans[i]=1;
                curr=i;
            }
            else if(i&1){
                ans[i]=ans[i-1]+1;
            }
            else{
                ans[i]=ans[i-curr]+1;
            }
        }
        return ans;
    }
};