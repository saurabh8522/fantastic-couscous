class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        int start[n],end[n];
        start[n-1]=arr[n-1];
        end[0]=arr[0];
        int ans=arr[0];
        for(int i=1;i<n;i++){
            end[i]=max(end[i-1]+arr[i],arr[i]);
            ans=max(ans,end[i]);
        }
        for(int i=n-2;i>=0;i--){
            start[i]=max(start[i+1]+arr[i],arr[i]);
            ans=max(ans,start[i]);
        }
        // ans=max(arr[0],arr[n-1]);
        for(int i=1;i<n-1;i++){
            ans=max(ans,end[i-1]+start[i+1]);
        }
        return ans;      
    }
};