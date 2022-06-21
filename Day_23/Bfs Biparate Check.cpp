bool check(vector<vector<int>> &graph,vector<int>&color,int src){
        queue<int>q;
        q.push(src);
        color[0] = 0;
        while(!q.empty()){
            int curNode = q.front();
            q.pop();
            for(int i=0; i<graph[curNode].size(); i++){
                int nextNode = graph[curNode][i];
                if(color[nextNode] == -1){
                    color[nextNode] = 1 - color[curNode];
                    q.push(nextNode);
                }
                else if(color[nextNode] == color[curNode])return false;
            }
        }
    return true;
}
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!check(graph,color,i))return false ;
            }
        }
        return true;
    }
};