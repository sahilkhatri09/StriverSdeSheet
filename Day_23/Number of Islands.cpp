class Solution {
public:
    int xi[4]={0,0,-1,1};
    int yi[4]={-1,1,0,0};
    bool isValid(int &x,int &y,vector<vector<char>>&grid){
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||grid[x][y]=='0')return false;
        return true;
    }
    void bfs(vector<vector<char>>&grid,int &x,int &y){
         queue<pair<int,int>>q;
        grid[x][y]='0';
        q.push({x,y});
        while(!q.empty()){
            int curx=q.front().first;
            int cury=q.front().second;
            q.pop();
            grid[curx][cury]='0';
            for(int i=0;i<4;i++){
                int ncurx=curx+xi[i];
                int ncury=cury+yi[i];
                if(isValid(ncurx,ncury,grid)){
                    grid[ncurx][ncury]='0';
                    q.push({ncurx,ncury});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    bfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};