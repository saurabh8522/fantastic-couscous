class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        map< pair<int,int>,int >mp;
        for(int i=0;i<n;i++){
            for(int j=-100;j<100;j++){
                mp[{i,j}]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=i-1;j--){
                int cd=A[i]-A[j];
                mp[{i,cd}]=mp[{j,cd}]+1;
            }
        }
        int ans=0;
        for(int i=2;i<n;i++){
            for(int j=-100;j<100;j++){
                if(mp[{i,j}]>=3){
                    cout<<i<<" "<<j<<endl;
                    ans+=mp[{i,j}]-2;
                }
            }
        }
        return ans;
    }
};