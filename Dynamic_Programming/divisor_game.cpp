class Solution {
public:
    bool divisorGame(int N) {
        if(N==1||N==3){
            return false;
        }
        else if(N==2){
            return true;
        }
        bool ans[N+1];
        memset(ans,false,sizeof(ans));
        ans[2]=true,ans[1]=ans[3]=false;
        for(int i=4;i<=N;i++){
            if(!ans[i-1]){
                ans[i]=true;
                continue;
            }
            for(int j=2;j<=sqrt(i);j++){
                if(i%j==0){
                    if(ans[i-j]==false||ans[i-i/j]==false){
                        ans[i]=true;
                        continue;
                    }
                }  
            }
        }
        return ans[N];
    }
};