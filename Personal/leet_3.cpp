//
//  leet_3.cpp
//  algorithms
//
//  Created by 김혜진 on 2020. 10. 18..
//  Copyright © 2020년 김혜진. All rights reserved.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int stringlen = s.length();
        int i = 0;
        int j = 0;
        
        set<char> substring;
        while(i < stringlen && j < stringlen){
            
            if(substring.find(s[j]) != substring.end()){ // if already in the set
                substring.erase(substring.find(s[i]));
                i++;
            }
            else{
                substring.insert(s[j]);
                j++;
                maxlen = max(maxlen, j-i);
            }
        }
        return maxlen;
    }
};
