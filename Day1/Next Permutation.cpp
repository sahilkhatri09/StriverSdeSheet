class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n = nums.size();
        int curIndex = n-1;
        int breakPoint = curIndex -1 ;
        while(breakPoint >=0 && nums[curIndex] <= nums[breakPoint]){
            curIndex--;
            breakPoint--;
        }
        
        if(breakPoint == -1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        
        curIndex = n-1;
        while(nums[curIndex] <= nums[breakPoint] )curIndex--;
        
        swap(nums[curIndex] , nums[breakPoint]);
        reverse(nums.begin() + breakPoint +1,nums.end());
    }
};