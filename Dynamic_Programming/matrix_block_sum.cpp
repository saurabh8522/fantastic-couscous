class NumMatrix {
public:
    vector< vector<int> >sum;
    int n,m;
    int returnsum(int r,int c){
        if(r<0||c<0) return 0;
        r=min(n-1,r);
        c=min(m-1,c);
        return sum[r][c];
    }
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()!=0){
             n=matrix.size();
        m=matrix[0].size();
        sum.resize(n);
        for(int i=0;i<n;i++){
            sum[i].resize(m);
        }
        sum[0][0]=matrix[0][0];
        
        for(int i=1;i<m;i++){
            sum[0][i]=matrix[0][i]+sum[0][i-1];
        }
        for(int i=1;i<n;i++){
            sum[i][0]=matrix[i][0]+sum[i-1][0];
        }
        for(int i=1;i<n;i++){
            // sum[i].resize(m);
            for(int j=1;j<m;j++){
                sum[i][j]=returnsum(i,j-1)+returnsum(i-1,j)-returnsum(i-1,j-1)+matrix[i][j];
                cout<<sum[i][j]<<" ";
            }
            cout<<endl;
        }
        }
       
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(sum.size()==0){
            return 0;
        }
        return returnsum(row2,col2)-returnsum(row1-1,col2)-returnsum(row2,col1-1)+returnsum(row1-1,col1-1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */