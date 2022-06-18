class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> bottom;
        map<int , int>m;
        queue<pair<Node*,int>>q;
        if(root)q.push({root,0});
        while(!q.empty()){
            Node* curNode = q.front().first;
            int curWidth = q.front().second;
            m[curWidth]=curNode->data;
            if(curNode->left)q.push({curNode->left,curWidth - 1});
            if(curNode->right)q.push({curNode->right,curWidth + 1});
            q.pop();
        }
        map<int,int> :: iterator it;
        for(it = m.begin(); it != m.end(); it++){
         bottom.push_back(it->second);
        }
        return bottom;
    }
};