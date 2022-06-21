class Solution {
  public:
    bool dfs(int src,vector<int>&visited,vector<int> adj[]){
        visited[src] = 1;
        for(int i=0;i<adj[src].size();i++){
            int curNode = adj[src][i];
            if(visited[curNode] == 0){
                if(dfs(curNode,visited,adj))return true;
            }
            else if(visited[curNode]==1 )return true;
        }
        visited[src] = 2;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i] == 0){
                if(dfs(i,visited,adj))return true;
            }
        }
        return false;
    }
};
