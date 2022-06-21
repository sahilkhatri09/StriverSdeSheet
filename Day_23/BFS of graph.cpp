class Solution {
  public:
   void getBfs(int s,vector<int> adj[],vector<bool>&visited,vector<int>&bfs){
       visited[s] = true;
       queue<int>q;
       q.push(s);
       
       while(!q.empty()){
           int curNode = q.front();
           bfs.push_back(curNode);
           q.pop();
           for(int i=0;i<adj[curNode].size();i++){
               if(visited[adj[curNode][i]]==false){
                   visited[adj[curNode][i]]=true;
                   q.push(adj[curNode][i]);
               }
           }
       }
   }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        vector<int>bfs;
        getBfs(0,adj,visited,bfs);
           
        return bfs;
    }
};
