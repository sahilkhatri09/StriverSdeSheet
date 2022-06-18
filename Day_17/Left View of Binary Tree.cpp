vector<int> leftView(Node *root)
{
    vector<int> left;
   queue<Node*>q;
   if(root)q.push(root);
   while(!q.empty()){
       int n = q.size();
       left.push_back(q.front()->data);
       while(n--){
           Node* curNode =q.front();
           if(curNode->left)q.push(curNode->left);
           if(curNode->right)q.push(curNode->right);
           q.pop();
       }
   }
   return left;
}