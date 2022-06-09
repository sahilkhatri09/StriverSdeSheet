vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
  
    priority_queue<int,vector<int>,greater<int>>pq;
    sort(A.begin() , A.end() , greater<int>());
   
    sort(B.begin() , B.end() , greater<int>());
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<B.size(); j++){
            int curSum = A[i] + B[j];
            if(pq.size() < C)pq.push(curSum);
            else if(pq.top() < curSum){
               pq.pop();
               pq.push(curSum);
            }
            else break;
        }
    }

    vector<int> ans(C,0) ;
    while(!pq.empty()){
        ans[--C] = pq.top();
        pq.pop();
    }
    
    return ans;
}
