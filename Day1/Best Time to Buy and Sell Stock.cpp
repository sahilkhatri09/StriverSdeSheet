class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int overAllProfit = 0;
        int n = prices.size();
        
        for(int i=1; i<n ;i++){
            minPrice = min(minPrice , prices[i]);
          int todayProfit = prices[i] - minPrice;
            overAllProfit = max(todayProfit , overAllProfit);
        }
        return overAllProfit;
    }
};