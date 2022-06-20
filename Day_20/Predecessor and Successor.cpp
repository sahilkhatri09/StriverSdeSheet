void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    Node* temp = root;
    while(temp){
        if(temp->key <= key){
            temp = temp->right;
        }
        else{
            suc = temp;
            temp = temp->left;
        }
    }
    temp = root;
    while(temp){
        if(temp->key >= key){
            temp = temp->left;
        }
        else{
            pre = temp;
            temp = temp->right;
        }
    }
}