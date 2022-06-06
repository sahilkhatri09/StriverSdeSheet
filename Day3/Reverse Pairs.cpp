class Solution {
public:
    int merge(vector<int>&nums,vector<int>&temp,int left,int mid ,int right){
        int i = left;
        int k = left;
        int j = mid + 1;
        int ans = 0;
        for( i =left; i<=mid; i++){
            while(j <= right && (nums[i] > 2LL *nums[j])) j++;
            ans += (j - mid - 1);
        }
        j = mid + 1;
        i = left;
        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }
        while(j <= right){ temp[k++] = nums[j++];}
        while(i <= mid) temp[k++] = nums[i++];
        
        for(int i = left; i <= right; i++) nums[i] = temp[i];
        
        return ans;
    }
    int mergeSort(vector<int> &nums,vector<int> &temp,int left ,int right ){
        int ans = 0;
        if(left < right){
            int mid = (left + right) / 2;
          ans +=  mergeSort(nums, temp, left, mid);
          ans +=  mergeSort(nums, temp, mid+1, right);
          ans +=  merge(nums, temp, left, mid, right);
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        
        vector<int>temp(nums.size(), 0);
      return  mergeSort(nums, temp, 0, nums.size()-1);
    }
};