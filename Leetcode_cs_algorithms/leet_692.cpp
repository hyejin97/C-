//
//  leet_692.cpp
//  C++
//
//  Created by 김혜진 on 2020. 10. 3..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//692.Top K Frequent Words
//priority queue
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> M;
        for(auto word : words){
            if(M.find(word) == M.end()) M[word] = 1;
            else M[word] += 1;
        }
        
        //minheap
        //primarily sort by first argument int, in ascending order
        //if same key, sort by reversed alphabetical order
        struct comp{
            //assume that a is larger than b
            bool operator()(pair<int, string> a, pair<int, string> b){
                if(a.first != b.first) return b.first < a.first; //this returns true -> smaller one precedes
                else return a.second < b.second; //this returns false -> larger one precedes
            }
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> PQ;
        for(auto it = M.begin(); it != M.end(); it++){
            PQ.push({it->second, it->first});
            if(PQ.size() > k) PQ.pop();
        }
        vector<string> res;
        for(int i = 0; i < k; i++){
            res.insert(res.begin(), PQ.top().second);
            PQ.pop();
        }
        return res;
    }
};
