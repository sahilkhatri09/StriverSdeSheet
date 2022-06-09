class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans  = -1;
        while(low <= high){
            int mid = (high + low )/2;
            if(mid > 0 && nums[mid] == nums[mid - 1]){
                if(mid % 2 == 0){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else if(mid < nums.size() - 1 && nums[mid] == nums[mid +1]){
                if(mid % 2 == 0){
                    low = mid + 1;
                }
                else{
                    high = mid -1;
                }
            }
            else{
                ans = nums[mid];
                break;
            }
            
        }
        return ans;
    }
};