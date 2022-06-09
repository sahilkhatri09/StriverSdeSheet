class MyQueue {
    stack<int>pre,post;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
       while(!post.empty()){
           pre.push(post.top());
           post.pop();
       }
        pre.push(x);
    }
    
    int pop() {
        while(!pre.empty()){
            post.push(pre.top());
            pre.pop();
        }
        int val = -1;
        if(!post.empty()){
            val = post.top();
             post.pop();
        }
          return val;
    }
    
    int peek() {
          while(!pre.empty()){
            post.push(pre.top());
            pre.pop();
        }
        int val = -1;
        if(!post.empty()){
            val = post.top();
        }
          return val;
    }
    
    bool empty() {
       return pre.size() == 0 && post.size() ==0;
    }
};
