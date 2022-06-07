class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        
        for(int i=0; i<nums.size();){
            for( int j=i+1; j<nums.size();){
                int twoSum = nums[i] + nums[j];
                int reqSum = target - twoSum;
                int l = j + 1;
                int r = nums.size() - 1;
                while(l < r){
                    if(nums[l] + nums[r] == reqSum){
                        ans.push_back({ nums[i], nums[j], nums[l], nums[r]});
                        int pre = nums[l];
                        while(l < r && nums[l] == pre) l++;
                        pre = nums[r];
                        while(r > l && nums[r] == pre) r--;
                    }
                    else if(nums[l] + nums[r] < reqSum){
                        l++;
                    }
                    else r--;
                }
                int pre = nums[j];
                while(j < nums.size() && nums[j] == pre)j++;
            }
          int  pre = nums[i];
            while(i < nums.size() && nums[i] == pre)i++;
        }return ans;
    }
};