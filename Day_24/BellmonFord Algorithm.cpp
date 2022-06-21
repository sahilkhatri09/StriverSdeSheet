class Solution{
	public:
    
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int>dist(V,1e8);
        dist[S] = 0;
        for(int count = 1; count<V;  count++){
                for(int k=0 ;k<adj.size() ;k++){
                    int curNode = adj[k][0];
                    int nextNode =  adj[k][1];
                    int curWeight =  dist[curNode];
                    int nextWeight = dist[nextNode];
                    int tempDist =  adj[k][2];
                    if(curWeight != 1e8 && nextWeight > curWeight + tempDist){
                        dist[nextNode] = curWeight + tempDist;
                    }
                }
        }
        return dist;
    }
};
