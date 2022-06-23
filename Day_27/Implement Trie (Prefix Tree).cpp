class TrieNode{
    public:
    TrieNode* child[26];
    bool isEnd;
    
    TrieNode(){
        for(int i=0;i<26;i++)child[i]=NULL;
        isEnd = false;
    }
    
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(cur->child[idx] == NULL){
                cur->child[idx] = new TrieNode();
            }
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(cur->child[idx] == NULL)return false;
            cur = cur->child[idx];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode * cur = root;
        for(int i = 0; i < prefix.size(); i++){
            int idx = prefix[i] - 'a';
            if(cur->child[idx] == NULL)return false;
            cur = cur->child[idx];
        }
        return true;
    }
};