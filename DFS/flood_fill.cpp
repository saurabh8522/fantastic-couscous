class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int start=image[sr][sc];
        int n=image.size(),m=image[0].size();
        queue< pair<int,int> >q;
        q.push({sr,sc});
        bool visited[n][m];
        memset(visited,false,sizeof(visited));
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            if(visited[p.first][p.second]){
                continue;
            }
            visited[p.first][p.second]=true;
            image[p.first][p.second]=newColor;
            if(p.second-1>=0&&image[p.first][p.second-1]==start){
                q.push({p.first,p.second-1});
            }
            if(p.second+1<=m-1&&image[p.first][p.second+1]==start){
                q.push({p.first,p.second+1});
            }
            if(p.first-1>=0&&image[p.first-1][p.second]==start){
                q.push({p.first-1,p.second});
            }
            if(p.first+1<=n-1&&image[p.first+1][p.second]==start){
                q.push({p.first+1,p.second});
            }
        }
        return image;
    }
};