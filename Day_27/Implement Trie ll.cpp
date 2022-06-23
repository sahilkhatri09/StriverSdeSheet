class TrieNode{
    public:
    TrieNode* child[26];
    int prefixEnd;
    int wordEnd;
    TrieNode(){
    for(int i = 0; i < 26; i++)child[i] = NULL;
        prefixEnd = 0;
        wordEnd == 0;
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
            cur->prefixEnd ++;
        }
        cur->wordEnd++;
    }

    int countWordsEqualTo(string &word){
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';
            if(cur->child[idx] == NULL)return 0;
            cur = cur->child[idx];
        }
        return cur->wordEnd;
    }

    int countWordsStartingWith(string &word){
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';
            if(cur->child[idx] == NULL)return 0;
            cur = cur->child[idx];
        }
        return cur->prefixEnd;
    }

    void erase(string &word){
         TrieNode* cur = root;
        for(int i = 0; i< word.length(); i++){
            int idx = word[i] - 'a';
            cur = cur->child[idx];
            cur->prefixEnd--;
        }
        cur->wordEnd--;
    }
};

