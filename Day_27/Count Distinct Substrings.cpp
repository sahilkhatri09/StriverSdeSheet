class Node{
  public: 
    Node* child[26];
    Node(){
        for(int i = 0; i < 26; i++)child[i] = NULL;
    }
    Node* getKey(char &a){
        return child[a-'a'];
    }
};
int countDistinctSubstrings(string &s)
{
   Node* root = new Node();
    int count = 1;
    for(int i = 0; i < s.length(); i++){
        Node* node = root;
        for(int j = i;j < s.length(); j++){
           int idx = s[j] - 'a';
            if(node->child[idx] == NULL){
                node->child[idx] = new Node();
                count++;
            }
            node = node->child[idx];
        }
    }
    return count;
}