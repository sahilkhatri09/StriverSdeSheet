void changeTree(BinaryTreeNode < int > * root) {
    if(root == NULL)return;
    int childSum = 0;
    if(root->left)childSum += root->left->data;
    if(root->right)childSum += root->right->data;
    if(childSum < root->data){
        if(root->left)root->left->data = root->data;
        else if(root->right)root->right->data = root->data;   
    }
    changeTree(root->left);
    changeTree(root->right);
    int totalSum = 0;
    if(root->left)totalSum += root->left->data;
    if(root->right)totalSum += root->right->data;
    if(root->left || root->right)root->data = totalSum;
}  