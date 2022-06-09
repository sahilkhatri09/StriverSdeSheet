class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;
        while(low <= high){
            int mid = (high + low) / 2;
            if(nums[mid] == target){
                ans = mid ;
                break;
            }
            else if(nums[mid]>=nums[low]){
                if(target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && nums[high] >= target){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
    return ans;
    }
};