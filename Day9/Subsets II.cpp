class Solution {
    vector<vector<int>> ans;
public:
    void helper(vector<int> &nums,int idx,vector<int> temp){
        ans.push_back( temp );
        for(int i = idx; i< nums.size();i++){
            if(i > idx && nums[i] == nums[i-1])continue;
            
            temp.push_back(nums[i]);
            helper(nums,i + 1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        helper(nums, 0, temp);
        return ans;
    }
};