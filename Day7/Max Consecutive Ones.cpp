class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i < nums.size(); i++){
            if(nums[i] == 1){
                int j = i;
                while(j < nums.size() && nums[j] == 1)j++;
                ans = max(ans,j-i);
                i = j;
            }
        }
        return ans;
    }
};


// Approach 2
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            nums[i] == 1 ? count++ : count = 0;
            ans =max(ans,count);
        }
        return ans;
    }
};