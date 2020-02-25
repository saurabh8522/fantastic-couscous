class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0) return 0;
        int m=matrix[0].size();
        if(matrix.empty()){
            return 0;
        }
        int mat[n][m];
        for(int i=0;i<m;i++){
            mat[0][i]=matrix[0][i]-'0';
        }
        int ans=0;
        for(int i=0;i<n;i++){
            mat[i][0]=matrix[i][0]-'0';
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='0'){
                    mat[i][j]=0;
                }
                else{
                    mat[i][j]=min(mat[i-1][j],min(mat[i][j-1],mat[i-1][j-1]))+1;
                    ans=max(ans,mat[i][j]);
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     stack<int>s;
        //     int j=0;
        //     while(j<m){
        //         if(s.empty()||mat[i][j]>mat[i][s.top()]){
        //             s.push(j++);
        //         }
        //         else{
        //             int h=s.top();
        //             s.pop();
        //             int w=s.empty()?(j):(j-s.top()-1);
        //             cout<<i<<" "<<h<<" "<<mat[i][h]<<" "<<w<<endl;
        //             if(w==mat[i][h]){
        //                 int area=w*w;
        //                 ans=max(ans,area);
        //             }
        //         }
        //     }
        //     while(!s.empty()){
        //         int h=s.top();
        //         s.pop();
        //         int w=s.empty()?(m):(m-s.top()-1);
        //         cout<<i<<" "<<h<<" "<<mat[i][h]<<" "<<w<<endl;
        //         if(w==mat[i][h]){
        //             int area=w*w;
        //             ans=max(area,ans);
        //         }
        //     }
        // }
        return ans;
    }
};