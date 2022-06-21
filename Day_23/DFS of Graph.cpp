class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void getDfs(int s, vector<int> adj[],vector<int> &dfs,vector<bool> &visited){
        visited[s] = true;
        dfs.push_back(s);
        for(int i=0;i<adj[s].size();i++){
            int curNode = adj[s][i];
            if(visited[curNode] == false){
              getDfs(curNode,adj,dfs,visited); 
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfs;
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                getDfs(i,adj,dfs,visited);
            }
        }
        return dfs;
    }
};