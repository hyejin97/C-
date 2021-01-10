class Solution {
public:
    vector<vector<int>> res;
    vector<int> isused {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(0, 1, k, n);
        return res;
    }
    
    void backtrack(int cursum, int start, int k, int n){
        if(cursum == n){
            vector<int> el;
            for(int i = 0; i < 10; i++){
                if(isused[i]){
                    el.push_back(i);
                }
            }
            if(el.size() == k) res.push_back(el);
            return;
        }
        
        for(int i = start; i < 10; i++){ //by setting start point, remove the duplicate cases that are caused by starting from the 1 everytime scanning possible combinations
            if(isused[i] == 0){
                isused[i] = 1;
                cursum += i;
                backtrack(cursum, i+1, k, n);
                cursum -= i;
                isused[i] = 0;
            }        
        }
        
    }
};
