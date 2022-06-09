class MedianFinder {
public:
    priority_queue<int , vector<int> ,greater<int>> high;
    priority_queue<int> low;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(low.size() == 0 || num <= low.top()) low.push(num);
       else high.push(num);
       
        if(low.size() > high.size() + 1){
            high.push(low.top());
            low.pop();
        }
        if(high.size() > low.size()){
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        if(low.size() == high .size()){
            return (low.top() + high.top()) / 2.0;
        }
        else return low.top() * 1.0;
    }
};