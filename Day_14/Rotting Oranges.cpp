 class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int count = 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2) q.push({i,j});
               else if(grid[i][j] == 1) count++;
            }
        }

        int ans = 0;
        vector<int>row = {1,-1,0,0};
        vector<int>col = {0,0,1,-1};
        while(!q.empty()){
            int j = q.size();
            while(j--){
            int k = q.front().first;
            int l = q.front().second;
            q.pop();
           
                for(int i=0; i<4; i++){
                int a = k + row[i];
                int b = l + col[i];
                    if(a >= 0 && a < grid.size() && b >= 0 && b<grid[0].size() && grid[a][b] == 1){
                        count--;
                        grid[a][b] = 2;
                        q.push({a,b});
                     }
                }
            }
            ans++;
        }
        
        if(count == 0)return ans > 0 ? --ans : ans;
        return -1;
    }
};