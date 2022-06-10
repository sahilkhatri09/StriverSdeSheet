class Node{
    public:
    int data,min;
    Node(int data,int min){
        this->data = data;
        this->min = min;
    }
};
class MinStack {
    stack<Node*>st;
public:
    MinStack() {
        while(!st.empty()) st.pop();
    }
    
    void push(int val) {
        Node *curNode;
        if(st.empty()){
            curNode = new Node(val,val);
        }
        else{
            curNode = new Node(val,min(val,st.top()->min));
        }
        st.push(curNode);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top()->data;
    }
    
    int getMin() {
        return st.top()->min;
    }
};
