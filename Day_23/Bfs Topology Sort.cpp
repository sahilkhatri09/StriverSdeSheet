class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>topologySort;
	    vector<int>indegree(V,0);
	    for(int i=0; i<V; i++){
	        for(int j=0; j<adj[i].size(); j++)
	            indegree[adj[i][j]]++;
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i] == 0)q.push(i);
	    }
	    while(!q.empty()){
	        int curNode = q.front();
	        q.pop();
	        topologySort.push_back(curNode);
	        for(int i=0;i<adj[curNode].size();i++){
	            int newNode = adj[curNode][i];
	            indegree[newNode]--;
	            if(indegree[newNode] == 0){
	                q.push(newNode);
	            }
	        }
	    }
	    return topologySort;
	}
};