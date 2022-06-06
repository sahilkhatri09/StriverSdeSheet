class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        pascalTriangle.push_back({1});
        
        for(int row =2; row<= numRows ; row++){
            vector<int> curRow(row,1);
    
            int preRowIdx = row - 2;
            int preRowSize =pascalTriangle[row - 2].size();
            
            for(int i=1; i<preRowSize ;i++){
                int curEle = pascalTriangle[preRowIdx][i] + pascalTriangle[preRowIdx][i-1];
                curRow[i] = curEle;
            }
            
            pascalTriangle.push_back(curRow);
        }
        
        return pascalTriangle;
    }
};