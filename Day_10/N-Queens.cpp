class Solution {
    vector<vector<string>> ans;
    
public:
    bool isValid(vector<string> & temp,int row ,int col){
        for(int i=0;i<row;i++){
            if(temp[i][col] == 'Q')return false;
        }
        
        int i = row -1 ;
        int j = col -1;
        while(i>=0 && j>=0){
            if(temp[i][j] == 'Q')return false;
            i--;
            j--;
        }
        
        i = row - 1;
        j = col + 1;
        while(i>=0 && j< temp.size()){
            if(temp[i][j] == 'Q')return false;
            i--;j++;
        }
        
        return true;
    }
    void helper(vector<string> &temp,int n,int idx){
        if(idx == n)ans.push_back(temp);
        
        for(int i=0; i<n; i++){
            if(isValid(temp,idx,i)){
                temp[idx][i] = 'Q';
                helper(temp, n, idx + 1);
                temp[idx][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string a(n,'.');
        vector<string> temp(n,a);
        helper(temp,n,0);
        return ans;
    }
};