class Solution {
public:
    vector<int> res;
    vector<int> numsSameConsecDiff(int n, int k) {
        //graph : nodes -> 0, 1, ... 9 / edges -> (0,k), (1, k-1), (2, k-2), (3, k-3), ...(9, k-9)
        for(int i = 1; i < 10; i++){
            if(i + k < 10 || i - k >= 0)
                explore(1, i, n, k);
        }
        return res;
    }
    
    void explore(int cnt, int curr, int n, int k){
        if(cnt == n){
            res.push_back(curr);
            return;
        }
        int bg, sm;
        if((bg = (curr % 10) + k) < 10)
            explore(cnt + 1, 10 * curr + bg, n, k);
        if((sm = (curr % 10) - k) >= 0 && bg != sm)
            explore(cnt + 1, 10 * curr + sm, n, k);
        
    }
};
