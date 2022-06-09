// Stack class.
class Stack {
    int *arr;
    int top1;
    int size;
 
public:
    
    Stack(int capacity) {
       arr = new int [capacity];
        top1 = -1;
        size = capacity;
    }

    void push(int num) {
        top1 ++;
        if(top1 == size){
           top1--; 
        }
        else{
            arr[top1]=num;
        }
    }

    int pop() {
        if(top1 == -1){
            return -1;
        }
        top1 --;
        return arr[top1+1];
        
    }
    
    int top() {
        if(top1 == -1)return -1;
        else return arr[top1];
    }
    
    int isEmpty() {
        return top1 == -1;
    }
    
    int isFull() {
        return top1 == size;
    }
    
};