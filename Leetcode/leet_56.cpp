class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //brut-fort 
        //sort by start items and traversing the sorted array, if an end item is bigger than 
        //the current largest end value, merge two intervals
        //O(nlogn) of sorting items and O(n) traversing the array, so total O(nlogn).
        
        int numitem = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<int> curmax = intervals[0];
        vector<vector<int>> merged;
        for(int i = 0; i < numitem; i++){
            if(curmax[1] >= intervals[i][0] && merged.size() != 0){ //merge
                merged.pop_back();
                
                vector<int> newitem;
                newitem.push_back(curmax[0]);
                newitem.push_back(max(curmax[1], intervals[i][1]));
                merged.push_back(newitem);
                
            }
            else{
                merged.push_back(intervals[i]);
            curmax = merged.back();
        }
        
        return merged;
    }
};
