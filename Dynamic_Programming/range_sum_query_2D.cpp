class NumMatrix {
public:
	vector< vector<int> >sum;
	int n,m;
	int returnsum(int r,int c){
		r=max(0,r);
        c=max(0,c);
        r=min(n-1,r);
        c=min(m-1,c);
        return sum[r][c];
	}
    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix.size();
        if(n==0){
        	return 0;
        }
        m=matrix[0].size();
        sum.resize(n);
        for(int i=0;i<n;i++){
        	sum[i].resize(m);
        	for(int j=0;j<m;j++){
        		sum[i][j]=sumRegion(0,0,i,j-1)+sumRegion(0,0,i-1,j)-sumRegion(0,0,i-1,j-1)+matrix[i][j];
        	}
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return returnsum(row2,col2)-returnsum(row1,col2-1)-returnsum(row2,col1-1)+returnsum(row1-1,col1-1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */