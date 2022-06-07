Node *flatten(Node *root)
{
    Node* dummy = new Node(-1);
    Node* head = dummy;
    priority_queue< pair<int,Node*> , vector<pair<int,Node*>> , greater<pair<int,Node*>>> pq;
    while(root){
        pq.push({root->data , root});
        root = root->next;
    }
    while(!pq.empty()){
       Node* temp = pq.top().second;
       pq.pop();
       
       dummy->bottom = temp;
       dummy = dummy->bottom;
       
       if(temp->bottom != NULL){
           Node* curNode = temp->bottom;
           int curData = curNode->data;
           pq.push({curData , curNode});
       }
        
        
    }
    return head->bottom;
   
}
