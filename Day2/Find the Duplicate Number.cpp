class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int nextIdx = abs( nums[i]);
            if(nums[nextIdx]<0){
                return nextIdx;
            }
            nums[nextIdx]*=-1;
        }
        return -1;
    }
};