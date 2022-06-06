class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false;
        bool firstCol = false;
        int n = matrix.size();
        int m = matrix[0].size();
    
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int curPos = matrix[i][j];
                if(curPos == 0){
                    if(i == 0) firstRow = true;
                    if(j == 0) firstCol = true;
                matrix[0][j] = 0;
                matrix[i][0] = 0;
                }
            }
        }
        
       for(int i=1;i<n; i++){
           for(int j=1; j<m; j++){
               if(matrix[i][0] == 0 || matrix[0][j] == 0){
                   matrix[i][j] = 0;
               }
           }
       }
       if(firstRow){
           for(int j=0;j<m;j++)matrix[0][j] = 0;
       }
       if(firstCol){
           for(int i=0;i<n;i++)matrix[i][0] = 0;
       }
        
    }
};