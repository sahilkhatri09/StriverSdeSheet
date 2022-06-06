class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int tempSum = 0;
        int n = nums.size();
        for(int i=0; i<n ;i++){
            tempSum += nums[i];
            if(tempSum < nums[i]){
                tempSum = nums[i];
            }
            maxSum = max(maxSum , tempSum);
        }
        return maxSum;
    }
};