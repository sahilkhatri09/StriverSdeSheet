class Solution{
    vector<string> ans;
    bool valid(int i,int j,vector<vector<bool>>&visited,vector<vector<int>> &m){
        if(i<0||j<0||i>=visited.size()||j>=visited[0].size()||visited[i][j]==true ||m[i][j]==0)return false;
        return true;
    }
    void solve(vector<vector<int>> &m,int i,int j,string &temp,vector<vector<bool>> &visited){
        if(i == m.size()-1 && j == m.size()-1){
            ans.push_back(temp);
            return;
        }
        
        visited[i][j] = true;
        if(valid(i+1,j,visited,m)){
            temp += 'D';
            solve(m, i+1, j, temp, visited);
            temp.pop_back();
        }
        if(valid(i-1,j,visited,m)){
            temp += 'U';
            solve(m, i-1, j, temp, visited);
            temp.pop_back();
        }
        if(valid(i, j+1, visited, m)){
            temp += 'R';
            solve(m, i, j+1, temp, visited);
            temp.pop_back();
        }
        if(valid(i, j-1, visited, m)){
            temp += 'L';
            solve(m, i, j-1, temp, visited);
            temp.pop_back();
        }
       
        visited[i][j] = false;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
     
        if(m[0][0] == 0)return {};
        string temp = "";
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        visited[0][0] = true;
        solve(m,0,0,temp,visited);
        return ans;
    }
};