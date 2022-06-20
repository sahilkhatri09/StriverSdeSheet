class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
         stack<Node*>st;
         if(node)st.push(node);
         
         while(!st.empty()){
            Node* curNode = st.top();
            st.pop();
            if(curNode->right)st.push(curNode->right);
            if(curNode->left)st.push(curNode->left);

            Node* leftNode = curNode->left;
            curNode->left = curNode->right;
            curNode->right = leftNode;
            
        }
    }
};