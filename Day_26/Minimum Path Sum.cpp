//APpraoch 1
//in  place bad idea
// can be implement same login n*m space
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=1; i<n; i++)grid[i][0] += grid[i-1][0];
        for(int j=1; j<m; j++)grid[0][j] += grid[0][j-1];
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                grid[i][j] += min(grid[i-1][j] , grid[i][j-1]);
            }
        }
    return grid[n-1][m-1];
    }
};

//Approach 2
// O(m) space
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> pre(m,0);
        pre[0] = grid[0][0];
        for(int i=1; i<m; i++)pre[i] = grid[0][i] + pre[i-1];
        
        for(int i=1; i<n; i++){
            pre[0] = grid[i][0] + pre[0];
            for(int j=1; j<m; j++){
               pre[j] = min(pre[j] + grid[i][j] , pre[j-1] + grid[i][j]);
            }
        }
    return pre[m-1];
    }
};