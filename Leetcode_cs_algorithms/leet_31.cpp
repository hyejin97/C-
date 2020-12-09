class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //traverse the array reversely -- until finding the first descending item
        int len = nums.size();
        for(int i = len - 1; i > 0; i--){
            if(nums[i-1] < nums[i]){
                //swap with the first larger item in the right side of the array
                for(int j = i; j < len; j++){
                    if(nums[j] <= nums[i-1]){
                        int tmp = nums[j-1];
                        nums[j-1] = nums[i-1];
                        nums[i-1] = tmp;
                        
                        //reverse nums[i:]
                        sort(nums.begin() + i, nums.end());
                        return;
                    }
                    else if(j == len-1){ //if reaches end
                        int tmp = nums[j];
                        nums[j] = nums[i-1];
                        nums[i-1] = tmp;
                        
                        sort(nums.begin() + i, nums.end());
                        return;
                    }
                }
            }
        }
        
        sort(nums.begin(), nums.end());
    }
    
};
