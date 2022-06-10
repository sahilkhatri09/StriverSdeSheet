class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans;
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int curIndex = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int right= i;
                ans = max(ans , (right - left - 1) * heights[curIndex]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int curIndex = st.top();
            st.pop();
            int left = st.empty() ? -1 : st.top();
            int right = n;
            ans = max(ans , (right - left - 1) * heights[curIndex]);
        }
     return ans;
    }
};