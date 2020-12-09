class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //brut force : three consecutive for-loops (O(n^3))
        //array of sum : O(n^2)
        //how to reduce to O(n)?
        // --> hashmap : {sum of a continous subarray,  # of the sum}
        //calculate cumulative sum of items from the first of the orray
        //case 1. a subarray starting from the first index has sum k
        //           -- sum == k
        //case 2. a subarray starting from some element(ith) to another element(jth) has sum k
        //           -- sum - k is in the map
        //count if case1 or 2 holds.
        
        map<int, int> m;
        map<int, int>::iterator it;
        int inputlen = nums.size();
        int sum = 0;
        int res = 0;
        
        for(int i = 0; i < inputlen; i++){
            sum = sum + nums[i]; //compute sum
            
            if(sum == k) res++; //case1
            if((it = m.find(sum-k)) != m.end()){ //case2
                res += it->second;
            }
            if((it = m.find(sum)) != m.end()){
                it->second += 1;
            }
            else{
                m.insert({sum, 1});
            }
            
        }
        return res;
    }
};
