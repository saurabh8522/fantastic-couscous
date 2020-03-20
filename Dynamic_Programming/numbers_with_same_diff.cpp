class Solution {
public:
    vector<int>ans;
    void find(int N,int n,int K,int res){
        if(N==0){
            ans.push_back(res);
            return ;
        }
        if(N==n){
            for(int i=1;i<=9;i++){
                if(i+K<=9||i>=K){
                    find(N-1,n,K,res*10+i);
                }
            }
        }
        else{
            if((res%10+K)<=9){
                find(N-1,n,K,res*10+(res%10)+K);
            }
            if((res%10)-K<=9&&(res%10)-K>=0){
                find(N-1,n,K,res*10+(res%10)-K);
            }
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N==1){
            vector<int>v;
            for(int i=0;i<=9;i++){
                v.push_back(i);
            }
            return v;
        }
        find(N,N,K,0);
        set<int>s;
        for(int i=0;i<ans.size();i++){
            s.insert(ans[i]);
        }
        ans.clear();
        while(!s.empty()){
            ans.push_back(*s.begin());
            s.erase(s.begin());
        }
        return ans;
    }
};