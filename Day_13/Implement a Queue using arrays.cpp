class Queue {
    int start,end,capacity,curSize;
    int *arr;

public:
    Queue() {
        start = -1;
        end = -1;
        curSize = 0;
        capacity = 5000;
        arr = new int [capacity];
    }
    
    bool isEmpty() {
        return curSize == 0;
    }

    void enqueue(int data) {
        if(start == -1)end =0;
        start = (start+1)%capacity;
        arr[start] = data;
        curSize++;
    }

    int dequeue() {
        if(curSize == 0)return -1;
        int ans = arr[end];
        end = (end + 1)%capacity;
        curSize--;
         return ans;
    }

    int front() {
        if(curSize == 0)return -1;
        return arr[end];
    }
};