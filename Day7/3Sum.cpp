class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        
        for(int i=0; i<nums.size();){
            int j = i + 1;
            int k = n - 1;
            if(nums[i] > 0)break;
            while(j < k){
                int curSum = nums[i] + nums[j] + nums[k] ;
                if(curSum == 0){
                    
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int temp1 = nums[j];
                    int temp2 = nums[k];
                    
                    while(j < k && nums[j] == temp1)j++;
                    while(j < k && nums[k] == temp2)k--;
                }
                else if(curSum > 0){
                    k--;
                }
                else{
                    j++;
                }   
            }
            
            int temp = nums[i];
            while(i < n && nums[i] == temp)i++;
        }
        return ans;
    }
};