//leet 46. Permutation

class Solution {
public:
    vector<int> isused;
    vector<int> arr;
    
    vector<vector<int>> permute(vector<int>& nums){
        int arrlen = nums.size();
        for(int i = 0; i < arrlen; i++){
            isused.push_back(0);
            arr.push_back(0);
        }
        
        vector<vector<int>> output;
        backtrack(0, arrlen, nums, output);
        return output;
    }
    
    void backtrack(int k, int arrlen, vector<int>& nums, vector<vector<int>>& output){
        if(k == arrlen){
            output.push_back(arr);
        }
        else{
            for(int i = 0; i < arrlen; i++){
                if(isused[i] == 0){
                    arr[k] = nums[i];
                    isused[i] = 1;
                    backtrack(k+1, arrlen, nums, output);
                    isused[i] = 0;
                }
            }
        }
    }
};
