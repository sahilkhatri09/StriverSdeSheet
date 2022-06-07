int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int>m;
    int ans = 0;
    int xr = 0;
    m[0] = 1;

    for(int i = 0; i < A.size(); i++){
        xr ^= A[i];
        int k = xr ^ B;

        if(m.find(k) != m.end()){
            ans += m[k];
        }

        m[xr]++ ;
    }
    return ans;
}
