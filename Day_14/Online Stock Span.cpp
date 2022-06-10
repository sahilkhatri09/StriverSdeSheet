class StockSpanner {
    stack<pair<int,int>>st;
public:
    StockSpanner() {
        while(!st.empty())st.pop();
    }
    
    int next(int price) {
        int curRes = 1;
        while(!st.empty() && st.top().first <= price){
            curRes += st.top().second;
            st.pop();
        }
        st.push({price , curRes});
        return curRes;
    }
};
