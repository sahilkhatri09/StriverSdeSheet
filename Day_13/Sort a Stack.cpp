void sortInsert(stack<int> &stack,int a){
    if(stack.empty()||stack.top()<=a){
        stack.push(a);
        return;
    }
    int n= stack.top();
    stack.pop();
    sortInsert(stack,a);
    stack.push(n);
}
void sortStack(stack<int> &stack)
{
    if(stack.empty())return ;
    int a=stack.top();
    stack.pop();
    sortStack(stack);
    sortInsert(stack,a);
    
}