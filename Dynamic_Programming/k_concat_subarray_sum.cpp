#define ll long long int
#define MOD 1000000007
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if(arr.size()==1){
           return arr[0]>0?arr[0]:0;
        }
        int  c=0;
        int gmax=max(c,arr[0]),lmax=max(c,arr[0]);
        int sum=arr[0];
        for(int i=1;i<arr.size();i++){
            // cout<<lmax<<" "<<arr[i]<<" "<<lmax+arr[i]<<endl;
            lmax=max(arr[i],lmax+arr[i]);
            lmax=max(c,lmax);
            gmax=max(gmax,lmax);
            // cout<<lmax<<" "<<gmax<<endl;
            sum+=arr[i];
        }
        // int sum=0;
        if(k==1){
            return gmax;
        }
        // cout<<gmax<<" "<<sum<<endl;
        int presum=0,ans1=0,sufsum=0,ans2=0;
        for(int i=0;i<arr.size();i++){
            presum+=arr[i];
            ans1=max(ans1,presum);
        }
        for(int i=arr.size()-1;i>=0;i--){
            sufsum+=arr[i];
            ans2=max(ans2,sufsum);
        }
        // cout<<ans1<<" "<<ans2<<endl;
        ll s1=(ll)sum*(ll)k,s2=(ll)sum*(ll)(k-2);
        s1=s1%MOD;s2=s2%MOD;
       ll ans=max((ll)gmax,max(s1,s2+ans1+ans2));
        return (int)max(ans,(ll)(ans1+ans2))%MOD;
    }
};