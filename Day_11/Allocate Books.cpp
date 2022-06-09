bool isPossible(vector<int> &A,int B,int pages){
    int n = 1;
    int temp = pages;
    for(int i=0; i<A.size(); i++){
       if(A[i] <= temp){
           temp -= A[i];
       }
       else{
           if(A[i] > pages)return false;
           temp = pages - A[i];
           n++;
       }
    }
    if(n > B)return false;
    return true;
}
int Solution::books(vector<int> &A, int B) {
    int ans = -1;
    int low = 0;
    int high = 0;
    for(int i=0; i<A.size(); i++)high += A[i];
    if(A.size() < B)return ans;

    while(low <= high){
        int mid = (high + low) / 2;
        bool possible = isPossible(A,B,mid);
        if(possible){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
