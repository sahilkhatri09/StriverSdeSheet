void getKmp(vector<int> &kmp , string &A){
    int j = 0 , i = 1;
    int n = A.length();
    while(i < n){
        if(A[i] == A[j]){
            kmp[i] = j + 1;
            j++;
            i++;
        }
        else{
            if(j != 0){
                j = kmp[j - 1];
            }
            else{
                kmp[i] = 0;
                i++;
            }
        }
    }
}
int Solution::solve(string A) {
    int n = A.length();
    string B = A;
    reverse(A.begin() , A.end());
    A = B + "#" + A;
    vector<int> kmp(A.size(),0);
    getKmp(kmp , A);
    return n - kmp[A.size() - 1];
    
}
