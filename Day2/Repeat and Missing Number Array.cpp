vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int bothXor =0;
    int n = A.size();
    for(int i=0; i<n; i++){
        bothXor ^= A[i];
        bothXor ^= (i+1);
    }
    int num1 = bothXor;
    int posRightSet = log2(bothXor & -bothXor);
    int rightSetBit =1;
    rightSetBit = rightSetBit << posRightSet;
    
    int x =0,y=0;
    for(int i=0; i<n; i++){
        if(A[i]&rightSetBit){
            x ^= A[i];
        }
        else{
            y ^= A[i];
        }
        if((i+1)&rightSetBit){
            x ^= (i+1);
        }
        else{
             y ^= (i+1);
        }
    }
    for(int i=0; i<n; i++){
        if(A[i]==x){
            return {x,y};
        }
    }
    return {y,x};
}
