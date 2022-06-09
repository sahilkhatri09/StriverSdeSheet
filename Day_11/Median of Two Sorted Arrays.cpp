class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int low = 0;
        int high = nums1.size();
        int k = (nums1.size() + nums2.size() + 1) / 2;
        int n = nums1.size() + nums2.size();
        double ans;
        
        while(low <= high){
            int mid = (low + high) / 2;
            int cnt1 = mid;
            int cnt2 = k - mid;
            
            int left1 = cnt1 == 0 ? INT_MIN : nums1[cnt1 - 1];
            int left2 = cnt2 == 0 ? INT_MIN : nums2[cnt2 - 1];
            int right1 = cnt1 == nums1.size() ? INT_MAX : nums1[cnt1];
            int right2 = cnt2 == nums2.size() ? INT_MAX : nums2[cnt2];
            
            if(left1 <= right2 && left2 <= right1){
                if(n % 2 == 0){
                    ans = (max(left1 , left2) + min(right1 , right2))/2.0;
                }
                else{
                    ans = max(left1 , left2);
                }
                break;
            }
            else if(left1 > right2){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};