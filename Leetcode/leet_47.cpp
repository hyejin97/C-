class Solution {
public:
    vector<vector<int>> perm;
    vector<int> arr;
    map<int, int> m;
    
    vector<vector<int>> permuteUnique(vector<int>& nums){
        int numsize = nums.size();
        for(int i = 0; i < numsize; i++){
            auto it = m.find(nums[i]);
            if(it != m.end()){
                it->second += 1;
            }
            else{
                m.insert({nums[i], 1});
            }
        }
        
        backtrack(0, numsize, nums);
        return perm;
    }
    
    void backtrack(int k, int numsize, vector<int>& nums){
        if(k == numsize){
            perm.push_back(arr);
            return;
        }
        
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second > 0){
                arr.push_back(it->first);
                it->second -= 1;
                backtrack(k+1, numsize, nums);
                arr.pop_back();
                it->second += 1;
            }
        }
        
    }
};
