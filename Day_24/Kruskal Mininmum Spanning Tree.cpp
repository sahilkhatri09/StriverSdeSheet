class Node{
   
    public:
     int first;
    int second;
    int weight;
    Node(int a,int b,int c){
        first = a;
        second = b;
        weight = c;
    }
};
class Solution
{
    int parentOf(int a ,vector<int>&parent){
        if(parent[a] == a)return a;
        return parent[a] = parentOf(parent[a],parent);
    }
    static bool cmp(Node* &a,Node* &b){
        return a->weight < b->weight;
    }
	public:

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>parent(V,0);
        vector<int>rank(V,0);
        for(int i=0;i<V;i++)parent[i]=i;
        vector<Node*>v;
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                Node* temp = new Node(i,adj[i][j][0],adj[i][j][1]);
                v.push_back(temp);
            }
        }
        int ans = 0;
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            int srcNode = v[i]->first;
            int desNode = v[i]->second;
            int weight = v[i]->weight;
            int parentsrc = parentOf(srcNode,parent);
            int parentdes = parentOf(desNode,parent);
            if(parentsrc != parentdes){
                if(rank[parentsrc] > rank[parentdes]){
                    parent[parentdes] = parent[parentsrc];
                }
                else if(rank[parentsrc] < rank[parentdes]){
                    parent[parentsrc] = parent[parentdes];
                }
                else{
                    rank[parentsrc]++;
                    parent[parentdes] = parent[parentsrc];
                }
                ans += weight;
            }
        }
        return ans;
        
    }
};