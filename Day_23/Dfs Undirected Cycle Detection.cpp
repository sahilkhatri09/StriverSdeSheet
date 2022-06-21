class Solution {
  public:

    bool dfs(int s,vector<bool>&visited,vector<int> adj[],int parent){
        visited[s] = true;
        for(int i=0; i<adj[s].size(); i++){
            int curNode = adj[s][i];
            if(visited[curNode] == false){
              if(dfs(curNode,visited,adj,s))return true;
            }
            else if(curNode != parent)return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       vector<bool>visited(V,false);
       for(int i=0; i<V; i++){
           if(visited[i] == false){
              if(dfs(i,visited,adj,-1))return true;
           }
       }
       return false;
    }
};
