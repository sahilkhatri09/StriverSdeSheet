class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       int ans = 0;
       vector<int> dist(V,INT_MAX);
       dist[0] = 0;
       vector<bool> mst(V,false);
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,0});
       while(!pq.empty()){
           int curNode = pq.top().second;
           int curDist = pq.top().first;
           pq.pop();
           if(dist[curNode] != curDist)continue;
           ans += curDist;
           mst[curNode] = true;
           for(int i=0;i<adj[curNode].size();i++){
               int nextNode = adj[curNode][i][0];
               int nextDist = adj[curNode][i][1];
               if(mst[nextNode] == false && dist[nextNode] >  nextDist){
                   dist[nextNode] = nextDist;
                   pq.push({ nextDist , nextNode});
               }
           }
       }
       return ans;
    }
};