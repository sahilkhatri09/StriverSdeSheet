class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n > m){
            return kthElement(arr2, arr1, m, n, k);
        }
        int low = max(0, k - m);
        int high = min(k , n);
        int ans =0;
        while(low <= high){
            int mid = (high + low) / 2;
            int cnt1 = mid;
            int cnt2 = k - mid;
            
            int left1 = cnt1 == 0 ? INT_MIN : arr1[cnt1 - 1];
            int left2 = cnt2 == 0 ? INT_MIN : arr2[cnt2 - 1];
            int right1 = cnt1 == n ? INT_MAX : arr1[cnt1];
            int right2 = cnt2 == m ? INT_MAX : arr2[cnt2];
            
            if(left1 <= right2 && left2 <= right1){
                ans = max(left1 , left2);
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