vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    if(A.size()<B)return ans;
    unordered_map<int,int>m;
    for(int i=0;i<B;i++)m[A[i]]++;
    ans.push_back(m.size());
    for(int i=B;i<A.size();i++){
        m[A[i-B]]--;
        if(m[A[i-B]]==0)m.erase(A[i-B]);
        m[A[i]]++;
        ans.push_back(m.size());
    }
    return ans;
    
}