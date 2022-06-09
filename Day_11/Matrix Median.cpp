int getLess(vector<vector<int> > &A,int row ,int val){
    int low = 0;
    int high = A[0].size() - 1;
    int ans = 0;
    
    while(low <= high){
        int mid = (low + high)/2;
        if(A[row][mid] > val){
            high = mid - 1;
        }
        else {
            ans = max(ans,mid + 1);
            low = mid + 1;
        }
    }
    return ans;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int low = 0;
    int high = n*m - 1 ;
    for(int i=0;i<n;i++){
        low = min(A[i][0] , low);
        high = max(high , A[i][m-1]);
    }
    int ans = high;
    while(low <= high){
        int mid = (low + high) / 2;
        int lessThan = 0;
        for(int i=0; i<n; i++){
            lessThan += getLess(A,i,mid);
        }
        if(lessThan >= ((n * m + 1) / 2)){
            high = mid - 1;
            ans = min(ans , mid);
        }
        else{
            
            low = mid + 1;
        }
    }
    return ans;
}

