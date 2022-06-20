class Solution {
public:
    Node* connect(Node* root) {
       queue<Node*>q;
       if(root != NULL)q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 1; i <= n; i++){
                Node* curNode = q.front();
                q.pop();
                if(i != n)curNode->next=q.front();
                if(curNode->left)q.push(curNode->left);
                if(curNode->right)q.push(curNode->right);
            }
        }
      return root;  
    }
};