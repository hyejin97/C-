//
//  leet_1.cpp
//  algorithms
//
//  Created by 김혜진 on 2020. 10. 15..
//  Copyright © 2020년 김혜진. All rights reserved.
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //hashmap
        //key : number, value : index
        map<int, int> m;
        map<int, int>::iterator it;
        
        vector<int> answ;
        for(int i = 0; i < nums.size(); i++){
            //watch out for type "auto"
            //if auto is used in the condition of if statement, it indicates boolean, not the item in the map
            if((it = m.find(target - nums[i])) != m.end()){
                //however, if auto is used here in the if statement, it indicates iterator
                //auto item = m.find(target - nums[i]);
                answ.push_back(it->second);
                answ.push_back(i);
                return answ;
            }
            else{
                m.insert({nums[i], i});
            }
        }
        answ.push_back(-1);
        answ.push_back(-1);
        return answ;
    }
};
