class Solution {
public:
    bool isValid(int x,int y,vector<vector<int>>&image,int v){
        if(x<0||y<0||x>=image.size()||y>=image[0].size()||image[x][y]!=v)return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nc) {
        vector<vector<bool>> visited(image.size(),vector<bool>(image[0].size(),false));
        int val=image[sr][sc];
        queue<pair<int,int>>q;
        int xi[4]={0,0,-1,1};
        int yi[4]={-1,1,0,0};
        if(image[sr][sc]==nc)return image;
        q.push({sr,sc});
        while(!q.empty()){
            int curx=q.front().first;
            int cury=q.front().second;
            q.pop();
            visited[curx][cury]=true;
            image[curx][cury]=nc;
            for(int i=0;i<4;i++){
                int ncurx=curx+xi[i];
                int ncury=cury+yi[i];
                if(isValid(ncurx,ncury,image,val)){
                    q.push({ncurx,ncury});
                }
            }
        }return image;
    }
};