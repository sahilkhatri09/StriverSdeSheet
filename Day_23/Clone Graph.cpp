class Solution {
    unordered_map<Node*,Node*>m;
    Node* getClone(Node* root){
        if(root == NULL)return NULL;
        Node* clone = new Node(root->val);
        m[root] = clone;
        int size = root->neighbors.size();
        for(int i = 0; i < size; i++){
            if(m.find(root->neighbors[i]) == m.end()){
                clone->neighbors.push_back(getClone(root->neighbors[i]));
            }
            else{
                clone->neighbors.push_back(m[root->neighbors[i]]);
            }
        }
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        return getClone(node);
    }
};