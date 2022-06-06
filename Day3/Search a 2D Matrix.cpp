// 1st approach O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix[0].size()-1;
        int n = matrix.size();
        
        while(i < n && j>=0){
            if(matrix[i][j] == target)return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }
    return false;
    }
};


// 2nd approach O(log(n*m))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 0;
        int high = m*n -1;
        while(low<=high){
            int mid = (low + high)/2;
            int curRow = mid/m;
            int curCol = mid%m;
            int curEle = matrix[curRow][curCol];
            if(curEle == target) return true;
            else if(curEle >target) high = mid -1;
            else low =mid + 1;
        }
        return false;
    }
};