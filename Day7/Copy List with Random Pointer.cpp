class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node*>m;
        m[NULL] = NULL;
        Node* dummy = new Node(-1);
        
        Node* temp1 = head;
        Node* temp2 = dummy;
        
        while(temp1){
            Node* temp3 = new Node(temp1->val);
            temp2->next = temp3;
            m[temp1] = temp3;
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        
        temp1 = head;
        temp2 =dummy->next;
        
        while(temp1){
            Node* temp3 = temp1->random;
            temp2->random = m[temp3];
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return dummy->next;
    }
};