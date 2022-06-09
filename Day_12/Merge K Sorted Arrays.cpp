class element{
    public:
    int val;
    int row;
    int col;
    element(int a,int b,int c){
        val = a;
        row = b;
        col = c;
    }
   
};
class comparator{
    public:
     bool operator()(element &A,element  &B){
    return A.val > B.val;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    priority_queue <element,vector<element>, comparator> pq;
    
    for(int i=0; i<kArrays.size(); i++){
       element temp(kArrays[i][0] , i, 0);
        pq.push(temp);
    }
    while(!pq.empty()){
        int curEle = pq.top().val;
        int curRow = pq.top().row;
        int curCol = pq.top().col;
        
        pq.pop();
        ans.push_back(curEle);
        
        if(kArrays[curRow].size()> curCol + 1){
           element temp2(kArrays[curRow][curCol + 1],curRow,curCol +1);
            pq.push(temp2);
        }
    }
    return ans;
}

