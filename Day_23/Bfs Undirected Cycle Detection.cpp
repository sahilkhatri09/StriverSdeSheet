class Solution {
  public:
    bool bfs(int s,vector<int> adj[],vector<bool>&visited){
        queue<pair<int,int>>q;
        visited[s] = true;
        q.push({s,-1});
        while(!q.empty()){
            int curNode = q.front().first;
            int curPar = q.front().second;
            q.pop();
            for(int i = 0; i < adj[curNode].size(); i++){
                int newNode = adj[curNode][i];
                if(visited[newNode] == false){
                    visited[newNode] = true;
                    q.push({newNode,curNode});
                }
                else if( newNode != curPar)return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(visited[i] == false){
                if(bfs(i,adj,visited) == true)return true;
            }
        }
        return false;
    }
};