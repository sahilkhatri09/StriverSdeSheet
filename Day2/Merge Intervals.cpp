class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back({intervals[0][0],intervals[0][1]});
        int n = intervals.size();
        
        for(int i=1; i<n ;i++){
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];
            
            int preEnd =mergedIntervals.back()[1];
            
            if(curStart > preEnd){
                mergedIntervals.push_back({curStart,curEnd});
            }
            else if(curEnd <= preEnd){
                continue;
            }
            else {
                mergedIntervals.back()[1] = curEnd;
            }
        }
        return mergedIntervals;
    }
};