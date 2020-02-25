class Solution {
public:
    int nthUglyNumber(int n) {
        int i2=0,i3=0,i5=0;
        vector<int>ans(n);
        ans[0]=1;
        int ug2=2,ug3=3,ug5=5;
        for(int i=1;i<n;i++){
            ans[i]=min(ug2,min(ug3,ug5));
            if(ans[i]==ug2){
                i2++;
                ug2=ans[i2]*2;
            }
            if(ans[i]==ug3){
                i3++;
                ug3=ans[i3]*3;
            }if(ans[i]==ug5){
                i5++;
                ug5=ans[i5]*5;
            }
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return ans[n-1];
    }
};