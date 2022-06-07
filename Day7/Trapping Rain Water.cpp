class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax (n,0);
        vector<int> rmax (n,0);
        
        int curLmax = 0;
        int curRmax = 0;
        
        for(int i=0; i<n; i++){
            curLmax = max(curLmax , height[i]);
            curRmax = max(curRmax , height[n-i-1]);
            lmax[i] = curLmax;
            rmax[n-i-1] = curRmax;
        }
        
        int maxWater = 0;
        for(int i=0; i<n; i++){
            int maxHeight = min(lmax[i] , rmax[i]);
            int curHeight = height[i];
            
            maxWater += (maxHeight - curHeight);
        }
        return maxWater;
    }
};