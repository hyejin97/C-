class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //using heap
        //{frequency, num}
        //save only k elements in the heap, insert/delete for n elements -> O(nlogk)
        //use hashmap to count the frequency of each item
        map<int, int> m; //{item, frequency}
        map<int, int>::iterator it;
        int inputlen = nums.size();
        for(int i = 0; i < inputlen; i++){
            if((it = m.find(nums[i])) != m.end()) it->second = it->second + 1;
            else m.insert({nums[i], 0});
        }
        
        struct comp{
            bool operator() (pair<int, int> a, pair<int, int> b){
                return b.first < a.first;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq; //minheap
        for(it = m.begin(); it != m.end(); it++){
            pq.push({it->second, it->first}); //{frequency, item}
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> output;
        while(!pq.empty()){
            output.push_back(pq.top().second);
            pq.pop();
        }
        return output;
    }
};
