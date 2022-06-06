class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curMaj = nums[0];
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == curMaj)count++;
            else if(count == 0){
                curMaj = nums[i];
                count = 1;
            }
            else{
                count --;
            }
        }
        return curMaj;
    }
};