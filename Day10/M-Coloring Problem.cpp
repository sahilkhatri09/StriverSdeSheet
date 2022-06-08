
bool isValid(int node,int nodeColor,vector<int>&color,bool graph[101][101],int n){
    for(int i=0;i<n;i++){
        if(i != node && graph[i][node]){
            if(color[i] == nodeColor)return false;
        }
    }
    return true;
}
bool helper(bool graph[101][101],int node,int m,int n,vector<int> &color){
    if(node == n)return true;
    for(int i=0;i<m;i++){
        if(isValid(node,i,color,graph,n)){
            color[node] = i;
            if(helper(graph,node+1,m,n,color)){
                return true;
            }
            color[node] = -1;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>color(n,-1);
        return helper(graph,0,m,n,color);
}