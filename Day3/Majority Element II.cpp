class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int max1 = -1;
        int max2 = -1;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            
            if(nums[i] == max1){
                count1++;
            }
            else if(nums[i] == max2){
                count2++;
            }
            else if(count1 == 0){
                max1  = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                max2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == max1) count1++;
            else if(nums[i] == max2) count2++;
        }
        
        vector<int>ans;
        
        if(count1>n/3) ans.push_back(max1);
        if(count2>n/3) ans.push_back(max2);
        
        return ans;
    }
};