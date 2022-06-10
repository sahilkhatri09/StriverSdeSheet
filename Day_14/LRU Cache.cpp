class Node{
    public:
    int key , val;
    Node *prev , *next;
    
    Node(int key , int val){
        this->val = val;
        this->key = key;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
    int capacity;
    unordered_map<int , Node*>um;
    Node* head,*tail;
    
public:
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    void putFirst(Node* curNode){
        curNode->prev->next = curNode->next;
        curNode->next->prev = curNode->prev;
        
        curNode->next = head->next;
        head->next->prev = curNode;
        head->next = curNode;
        curNode->prev = head;
    }
    int get(int key) {
        if(um.find(key) == um.end())return -1;
        Node* curNode = um[key];
        putFirst(curNode);
        return curNode->val;
    }
    
    void put(int key, int value) {
        if(um.find(key) != um.end()){
            Node* curNode = um[key];
            
            curNode->val = value;
            putFirst(curNode);
            return;
        }
        if(um.size() == capacity){
            Node* temp = tail->prev;
            temp->prev->next = tail;
            tail->prev = temp->prev;
            um.erase(temp->key);
            delete temp;
        }
        
        Node* curNode = new Node(key,value);
        head->next->prev = curNode;
        curNode->next = head->next;
        head->next = curNode;
        curNode->prev = head;
        
        um[key] = curNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */