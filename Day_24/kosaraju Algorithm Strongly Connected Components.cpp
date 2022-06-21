void dfs(int src,vector<int> adj[],vector<bool>&visited,stack<int>&st){
    visited[src] = true;
    for(int i=0;i<adj[src].size();i++){
        if(visited[adj[src][i]]==false){
            dfs(adj[src][i],adj,visited,st);
        }
    }
    st.push(src);
}
void dfs2(int src,vector<bool>&visited,vector<int>adj[],vector<int>&temp){
    visited[src] = true;
    temp.push_back(src);
    for(int i=0;i<adj[src].size();i++){
        int nextNode = adj[src][i];
        if(visited[nextNode] == false)dfs2(nextNode,visited,adj,temp);
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n];
    vector<int> revAdj[n];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        revAdj[edges[i][1]].push_back(edges[i][0]);
    }
    stack<int>st;
    vector<bool>visited(n,false);
    for(int i=0; i<n; i++){
        if(visited[i] == false){
            dfs(i,adj,visited,st);
        }
    }
    vector<vector<int>>ans;
    vector<bool>visited2(n,false);
    
    while(!st.empty()){
        int curNode = st.top();
        st.pop();
        vector<int>temp;
        if(visited2[curNode]==false) {
            dfs2(curNode,visited2,revAdj,temp);
        }
        if(temp.size()>0)ans.push_back(temp);
    }
    return ans;
}