class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>indegree(V,0);
        for(int i=0; i<V; i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
       int cnt = 0;
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int curNode = q.front();
            q.pop();
            cnt++;
            for(int i=0;i<adj[curNode].size();i++){
                int newNode = adj[curNode][i];
                indegree[newNode]--;
                if(indegree[newNode] == 0){
                    q.push(newNode);
                }
            }
        }
        
        return cnt != V;
    }
};
