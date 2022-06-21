class Solution
{
	public:
    void dfs(vector<int> adj[],int src,vector<int>&visited,vector<int>&ans){
        visited[src] = 1;
        for(int i=0;i<adj[src].size();i++){
            int curNode = adj[src][i];
            if(visited[curNode]==0){
                dfs(adj,curNode,visited,ans);
            }
        }
        visited[src] = 2;
        ans.push_back(src);
    }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int>visited(V,0);
	    for(int i=0; i<V; i++){
	        if(visited[i] == 0){
	            dfs(adj,i,visited,ans);
	        }
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};
