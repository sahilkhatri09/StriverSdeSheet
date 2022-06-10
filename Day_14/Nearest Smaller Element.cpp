vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> ans(A.size() , -1);
    stack<int>st;
    
    for(int i= A.size()-1; i>=0; i--){
        while(!st.empty() && A[i] < A[st.top()]){
            ans[st.top()] = A[i];
            st.pop();
        }
        st.push(i);
    }
    
    return ans;
}
