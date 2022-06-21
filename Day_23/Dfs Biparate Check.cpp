class Solution {
    bool dfs(vector<int>&color,int src,int pColor,vector<vector<int>>&graph){
        color[src] = 1 - pColor;
        for(int i=0;i<graph[src].size();i++){
            int nextNode = graph[src][i];
            if(color[nextNode] == -1){
                if(!dfs(color,nextNode,color[src],graph))return false;
            }
            else if(color[nextNode] == color[src])return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!dfs(color,i,0,graph))return false;
            }
        }
        return true;
    }
};