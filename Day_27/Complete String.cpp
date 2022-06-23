class TrieNode{
  public:
    TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        for(int i = 0; i < 26; i++)child[i] = NULL;
        isEnd = false;
    }
};
class Trie{
    TrieNode* root;
    public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string &word){
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';
            if(cur->child[idx] == NULL){
                cur->child[idx] = new TrieNode();
            }
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }
    bool checkPrefix(string &word){
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';
            cur = cur->child[idx];
            if(cur->isEnd == false)return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    Trie * trie = new Trie();
    for(int i = 0; i < a.size(); i++){
        trie->insert(a[i]);
    }
    string longest = "";
    for(int i = 0; i < a.size(); i++){
        if(trie->checkPrefix(a[i])){
            if(a[i].length() > longest.length()){
                longest = a[i];
            }
            else if(a[i].length() == longest.length()){
                if(a[i] < longest)longest = a[i];
            }
        }
    }
    if(longest == "")return "None";
    return longest;
}